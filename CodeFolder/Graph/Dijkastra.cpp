#include <bits/stdc++.h>

using namespace std;
#define int long long
#define inf 2000000000000000000
#define pii pair<int, int>
//#define mod 998244353
#define mod 1000000007

vector<pair<int, int>> adj[100005];
vector<int> min_cost(100005, inf), paths(100005, 0);
vector<int> min_step(100005, inf), max_step(100005, 0);

void build_path(int source){
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, source});
    min_cost[source] = 0;
    paths[source] = 1;
    min_step[source] = 0;

    while( !pq.empty() ){
        auto [cost, u] = pq.top();
        pq.pop();

        if(cost > min_cost[u])
            continue;

        for(auto [v, w] : adj[u]){
            if(min_cost[u] + w < min_cost[v]){
                min_cost[v] = min_cost[u] + w;
                paths[v] = paths[u];
                min_step[v] = min_step[u] + 1;
                max_step[v] = max_step[u] + 1;
                pq.push({min_cost[v], v});
            }
            else if(min_cost[u] + w == min_cost[v]){
                paths[v] = (paths[u] + paths[v]) % mod;
                min_step[v] = min(min_step[v], min_step[u] + 1);
                max_step[v] = max(max_step[v], max_step[u] + 1);
            }
        }
    }
}

void solve(int tc){
    int n, m;
    cin>>n>>m;
 
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    build_path(1);
    cout<<min_cost[n]<<" "<<paths[n]<<" "<<min_step[n]<<" "<<max_step[n];
}