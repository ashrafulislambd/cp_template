class DSU_Bip{    
public:
    vector<pair<int,int>> parent;
    vector<int> size, col;
    int cnt;
    DSU_Bip(int n) : parent(n + 1), size(n + 1, 1) {
        for(int i=0; i<=n; i++) {
            parent[i] = {i, 0};
        }
        cnt = n;
    }
 
    pair<int,int> root(int u){
        if(parent[u].first == u) return parent[u];
        int dis = parent[u].second;
        parent[u] = root(parent[u].first);
        parent[u].second ^= dis;
        return parent[u];
    }
 
    bool same(int u, int v){
        return root(u).first == root(v).first;
    }
    void merge(int u, int v){
        auto [uu, x] = root(u); u = uu;
        auto [vv, y] = root(v); v = vv;
        if(u == v) return;
        if(size[u] < size[v]) swap(u, v);
        parent[v] = {u, 1^x^y}, size[u] += size[v];
        cnt--;
    }
};