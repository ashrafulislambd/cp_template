class LCA{
    int N, K;
    vector<vector<int>> &adj, anc;
    vector<int> level;
 
public:
    
    LCA(vector<vector<int>> &adj): adj(adj){
        N = adj.size() - 1;
        K = 33 - __builtin_clz(N);
        anc.assign(N + 1, vector<int>(K));
        level.assign(N + 1, 0);
        initLCA(1);
    }
    
    void initLCA(int u, int p = 0){
        anc[u][0] = p;
        level[u] = level[p] + 1;
        for(int i = 1; i < K; i++){
            anc[u][i] = anc[anc[u][i - 1]][i - 1];
        }
        for(auto v: adj[u]) if(v != p){
            initLCA(v, u);
        }
    }
    int getAnc(int u, int k){
        for(int i = K - 1; i >= 0; i--)
            if(k & (1<<i)) u = anc[u][i];
        return u;
    }
    int lca(int u, int v){
        if(level[u] > level[v]) swap(u, v);
        v = getAnc(v, level[v] - level[u]);
        
        if(u == v) return u;
        for(int i = K - 1; i >= 0; i--){
            if(anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
        }
        return anc[u][0];
    }
    int dis(int u, int v){
        return level[u] + level[v] - 2 * level[lca(u, v)];
    }
};