int curr = 0;
vector<int> adj[501];
vector<int> parent(501, -1);
int mat[501][501];
int vis[501];
 
bool bfs(int n){
    queue<int> q;
    q.push(1);
 
    while( !q.empty() ){
        int u = q.front();
        q.pop();
 
        if(vis[u]) continue;
        vis[u] = 1;
 
        for(auto v : adj[u]){
            if(vis[v] == 0 && mat[u][v] > 0){
                q.push(v);
                parent[v] = u;
 
                if(v == n)
                    return true;
            }
        }
    }
 
    return false;
}
 
void solve(int tc){
    int n, m, tot_flow = 0, flag = 0;
    cin>>n>>m;
 
    while(m--){
        int u, v, c;
        cin>>u>>v>>c;
 
        if(mat[u][v] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        mat[u][v] += c;
    }
 
    while(bfs(n)){
        int flow = inf;
        memset(vis, 0, sizeof(vis));
 
        // determine flow
        for(int v = n; v != 1; v = parent[v]){
            int u = parent[v];
            flow = min(flow, mat[u][v]);
        }
 
        tot_flow += flow;
 
        // augment path
        for(int v = n; v != 1; v = parent[v]){
            int u = parent[v];  
 
            mat[u][v] -= flow;
            mat[v][u] += flow;
        }
    }
 
    cout<<tot_flow<<"\n";
}