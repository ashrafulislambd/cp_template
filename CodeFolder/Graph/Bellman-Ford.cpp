#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define inf 3000000000000
#define mod 998244353
//#define mod 1000000007

vector<int> adj[2501];
vector<int> vis(2501, 0), dist(2501, inf);

void solve(int tc){
    int n, m;
    cin>>n>>m;

    vector<tuple<int, int, int>> edges;
    queue<int> q;
    dist[1] = 0;

    while(m--){
        int u, v, c;
        cin>>u>>v>>c;
        adj[u].push_back(v);
        edges.push_back({u, v, -c});
    }

    for(int i=1; i<n; i++){
        bool flag = false;

        for(auto [u, v, cost_uv] : edges){
            if(dist[u] != inf && dist[u] + cost_uv < dist[v]){
                dist[v] = dist[u] + cost_uv;
                flag = true;
            }
        }

        if(flag == false){
            cout<<-dist[n]<<"\n";
            return;
        }
    }

    for(auto [u, v, cost_uv] : edges){
        if(dist[u] != inf && dist[u] + cost_uv < dist[v])
            q.push(u);
    }

    while( !q.empty() ){
        int u = q.front();
        q.pop();

        if(u == n){
            cout<<"-1\n";
            return;
        }

        vis[u] = 1;

        for(auto v : adj[u]){
            if(!vis[v])
                q.push(v);
        }
    }

    cout<<-dist[n]<<"\n";
}