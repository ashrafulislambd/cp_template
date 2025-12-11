// Lowest Common Subsequence
void solve(int tc){
    int n, m, i1 = -1, i2 = -1;
    string a, b;
    string res = "";
    cin>>a>>b;

    n = a.size();
    m = b.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[j-1] == b[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i = m, j = n;

    while(i > 0 && j > 0){
        if (b[i-1] == a[j-1]) {
            res += b[i-1];
            i--, j--;
        }
        else if (dp[i-1][j] >= dp[i][j-1]) 
            i--;
        else
            j--;
    }

    reverse(res.begin(), res.end());

    cout<<res<<"\n";
}