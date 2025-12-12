#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define inf 2000000000000000000
#define pii pair<int, int>
//#define mod 998244353
#define mod 1000000007
 
int succ[200005], ans[200005], vis[200005];
vector<pii> query[200005];
vector<int> rev_adj[200005], dist(200005, -inf);
 
void find_cycle(int u, vector<int> &cycle){
    int a = u, b = succ[u];
 
    while(a != b){
        a = succ[a];
        b = succ[succ[b]];
    }
 
    do{
        a = succ[a];
        cycle.push_back(a);
    } while(a != b);
}
 
void dfs(int u, int d){
    int temp = dist[u];
    dist[u] = d;
    vis[u] = 1;
 
    for(auto [v, i] : query[u]){
        if(dist[v] != -inf)
            ans[i] = dist[u] - dist[v];
        else
            ans[i] = -1;
    }
 
    for(auto v : rev_adj[u]){
        if(!vis[v])
            dfs(v, d+1);
    }
 
    dist[u] = temp;
}
 
void solve(int tc){
    int n, m;
    cin>>n>>m;
 
    for(int i=1; i<=n; i++){
        cin>>succ[i];
        rev_adj[succ[i]].push_back(i);
    }
 
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        query[u].push_back({v, i});
    }
 
    for(int i=1; i<=n; i++){
        if(vis[i])
            continue;
 
        vector<int> cycle;
        find_cycle(i, cycle);
 
        for(int i=0; i<cycle.size(); i++)
            dist[cycle[i]] = -i;
 
        dfs(cycle[0], 0);
 
        for(int i=0; i<cycle.size(); i++)
            dist[cycle[i]] = -inf;
    }
    
    for(int i=0; i<m; i++)
        cout<<ans[i]<<"\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int tests = 1;
    //cin>>tests; 
 
    for(int tc = 1; tc <= tests; tc++){
        solve(tc);
    }
 
    return 0;   
}
