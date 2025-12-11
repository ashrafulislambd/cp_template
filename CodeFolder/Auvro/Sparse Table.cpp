//Sparse table:
class sparse_table{
private:
    int n, m;
    vector<vector<int>> a;

    int logarithm(int a, int b){
        int r = 0, x = a;
        while(b >= a){ a *= x; r++; }
        return r;
    }

    int operation(int a, int b){
        //modify only here

        return __gcd(a, b);
        //return min(a, b);
        //return max(a, b);
    }

public:
    sparse_table(int n){
        this->n = n;
        m = logarithm(2, n);
        a.resize(1);
    }

    void insert(int x){ a[0].push_back(x); }

    void build(){
        a.resize(m+1, vector<int>(n, 0));

        for(int i=1; i<=m; i++){
            for(int j=0; j+(1<<i)-1 < n; j++){
                int left = a[i-1][j];
                int right = a[i-1][j + (1<<(i-1))];
                a[i][j] = operation(left, right);
            }
        }
    }

    // driver code query is 1 indexed
    int query(int i, int j){
        i--; j--;

        int x = logarithm(2, j-i+1);
        int left = a[x][i];
        int right = a[x][j - (1<<x) + 1];
        return operation(left, right);
    }
};
