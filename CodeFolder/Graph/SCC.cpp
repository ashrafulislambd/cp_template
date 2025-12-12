#include <bits/stdc++.h>
using namespace std;

// Global variables for Tarjan's Algorithm
vector<vector<int>> adj;
vector<int> tin, low, onStack;
stack<int> st;
int timer = 0, sccCount = 0;
vector<vector<int>> sccs;

void dfs(int u) {
    tin[u] = low[u] = ++timer;
    st.push(u);
    onStack[u] = 1;

    for (int v : adj[u]) {
        if (tin[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            // Back edge
            low[u] = min(low[u], tin[v]);
        }
    }

    // If u is the root of an SCC
    if (low[u] == tin[u]) {
        //cout<<"sss "<<u<<" "<<low[u]<<" "<<tin[u]<<"\n";

        sccCount++;
        vector<int> component;
        while (true) {
            int v = st.top(); st.pop();
            onStack[v] = 0;
            component.push_back(v);
            if (v == u) break;
        }
        sccs.push_back(component);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    onStack.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
        if (tin[i] == 0)
            dfs(i);

    cout << "Total SCCs: " << sccCount << "\n";
    for (int i = 0; i < sccCount; ++i) {
        cout << "SCC #" << i + 1 << ": ";
        for (int v : sccs[i]) cout << v << " ";
        cout << "\n";
    }
}
