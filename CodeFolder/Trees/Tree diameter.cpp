vector<int> adj[200005];
vector<int> vis(200005, 0), height(200005, -1);
int diameter = 0;

void dfs(int u){
    vis[u] = 1;
    int best1 = -1, best2 = -1;

    for(auto v : adj[u]){
        if(vis[v])
            continue;

        dfs(v);

        if(height[v] > best1){
            best2 = best1;
            best1 = height[v];
        }
        else if(height[v] > best2)
            best2 = height[v];
    }

    height[u] = best1 + 1;
    diameter = max(diameter, best1 + best2 + 2);
}