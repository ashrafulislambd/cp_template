//Sparse table:
class SparseTable{
private:
    int n, lvl;
    string op;
    vector<vector<int>> v;

public:
    void allocate(){
        v.resize(lvl);
        for(auto &p : v)
            p.resize(n);
    }

    int logarithm(int a, int b){
        int r = 0, x = a;
        while(b >= a){ a *= x; r++; }
        return r;
    }

    int operation(int x, int y){
        if(op == "min") return min(x, y);
        if(op == "max") return max(x, y);
        if(op == "gcd") return __gcd(x, y);
        if(op == "or") return (x|y);
        return (x&y);
    }

    SparseTable(vector<int> &arr, const string &op) {
        n = arr.size();
        this->op = op;
        lvl = logarithm(2, n) + 1;
        allocate();
        v[0] = arr;
        build();
    }

    void build(){
        for(int p=1; p<lvl; p++){
            int sz = 1LL<<p;
            for(int i=0; i+sz-1 < n; i++)
                v[p][i] = operation(v[p-1][i], v[p-1][i + sz/2]);
        }
    }

    int query(int l, int r){
        // change if not 1 based indexing
        // l--; r--;
        int p = logarithm(2, r-l+1);
        int sz = 1LL<<p;
        return operation(v[p][l], v[p][r-sz+1]);
    }
};
