#include <bits/stdc++.h>
 
using namespace std;

vector<int> adj[200005];
vector<int> taken(200005, 0), not_taken(200005, 0);

void dfs(int p, int u){
    for(auto v : adj[u]){
        if(v == p)
            continue;

        dfs(u, v);
        not_taken[u] += max(taken[v], not_taken[v]);
    }

    for(auto v : adj[u]){
        if(v == p)
            continue;

        int compliment = max(taken[v], not_taken[v]);
        int replace = not_taken[u] - compliment + not_taken[v];
        taken[u] = max(taken[u], replace + 1);
    }
}

void solve(int tc){
    int n;
    cin>>n;

    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 1);
    cout<<max(taken[1], not_taken[1])<<"\n";
} 