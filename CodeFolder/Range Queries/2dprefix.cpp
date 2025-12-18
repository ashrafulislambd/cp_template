// 2D prefix sum
class Matrix {
private:
    vector<vector<int>> v;
    int n, m;

public:
    // feed 0-indexed based matrix in
    Matrix(const vector<vector<int>>& in) {
        n = in.size();
        m = in[0].size();
        v = vector<vector<int>>(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) {
                v[i][j] = in[i-1][j-1] 
                        + v[i-1][j] 
                        + v[i][j-1] 
                        - v[i-1][j-1];
            }
        }
    }

    void boundCheck(int &x1, int &y1, int &x2, int &y2, int x){
        x1 = max(x1, 0LL+x);
        x1 = min(x1, n-1+x);
        y1 = max(y1, 0LL+x);
        y1 = min(y1, m-1+x);
        x2 = max(x2, 0LL+x);
        x2 = min(x2, n-1+x);
        y2 = max(y2, 0LL+x);
        y2 = min(y2, m-1+x);
    }

    // 0-indexed query
    int query0(int x1, int y1, int x2, int y2) {
        boundCheck(x1, y1, x2, y2, 0);

        return v[x2+1][y2+1]
             - v[x1][y2+1]
             - v[x2+1][y1]
             + v[x1][y1];
    }
};