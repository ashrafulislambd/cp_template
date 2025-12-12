class DSU{
private:    
    int n, numComponents;
    vector<int> parent, rank;

public:
    DSU(int n) : parent(n+1), rank(n+1, 0), n(n){
        iota(parent.begin(), parent.end(), 0);
        numComponents = n;
    }

    int root(int u){
        if(parent[u] == u) 
            return u;

        return parent[u] = root(parent[u]);
    }

    bool same(int u, int v){
        return root(u) == root(v);
    }

    void merge(int u, int v){
        u = root(u);
        v = root(v);

        if(u == v) 
            return;
        if(rank[u] > rank[v]) 
            swap(u, v);

        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        numComponents--;
    }

    int cntComponents(){
        return numComponents;
    }
};