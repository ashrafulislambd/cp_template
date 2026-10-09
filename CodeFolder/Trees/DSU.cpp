class DSU{    
public:
    vector<int> parent, size, score;
    int cnt;
    DSU(int n) : parent(n + 1), size(n + 1, 1), score(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
        cnt = n;
    }
 
    int root(int u){
        if(parent[u] == u) return u;
        return parent[u] = root(parent[u]);
    }
    bool same(int u, int v){
        return root(u) == root(v);
    }
    void merge(int u, int v){
        u = root(u), v = root(v);
        if(u == v) return;
        if(size[u] < size[v]) swap(u, v);
        parent[v] = u, size[u] += size[v];
        score[v] += score[u];
        cnt--;
    }
};