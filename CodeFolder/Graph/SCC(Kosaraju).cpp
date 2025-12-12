#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define inf 2000000000000000000
#define mod 998244353
//#define mod 1000000007
 
vector<vector<int>> adj, adj1, components;
vector<int> DFS_Stack, t_in;
int ssc_count = 0, timer = 0;
 
void Allocate(int n){
    adj.assign(n+1, vector<int>());
    adj1.assign(n+1, vector<int>());
    components.assign(n+1, vector<int>());
    t_in.assign(n+1, 0);
    ssc_count = 0;
    timer = 0;
}
 
void dfs(int u){
    t_in[u] = ++timer;
 
    for(auto v : adj[u]){
        if(t_in[v] == 0)
            dfs(v);
    }
    
    DFS_Stack.push_back(u);
}
 
void dfs1(int u){
    components[ssc_count].push_back(u);
    t_in[u] = ++timer;
 
    for(auto v : adj1[u]){
        if(t_in[v] == 0)
            dfs1(v);
    }
}
 
void solve(int tc){
    int n, m;
    cin>>n>>m;
 
    Allocate(n);
 
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj1[v].push_back(u);
    }
 
    for(int i=1; i<=n; i++){
        if(t_in[i] == 0)
            dfs(i);
    }
 
    fill(t_in.begin(), t_in.end(), 0);
    timer = 0;
 
    while( !DFS_Stack.empty() ){
        int v = DFS_Stack.back();
        DFS_Stack.pop_back();
 
        if(t_in[v] == 0){
            dfs1(v);
            ssc_count++;
        }
    }
 
    if(ssc_count == 1)
        cout<<"YES\n";
    else{
        cout<<"NO\n";
        cout<<components[1][0]<<" "<<components[0][0]<<"\n";
    }
}