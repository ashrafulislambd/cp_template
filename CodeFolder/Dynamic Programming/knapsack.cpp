// Bounded knapsack dp on weight
for(int i=0; i<n; i++){
    for(int j = w-weight[i]; j >= 0; j--){
        dp[j + weight[i]] = max(dp[j + weight[i]], dp[j] + value[i]);
    }
}

// Bounded knapsack dp on value
// v = sum of values (values[i])
vector<int> dp(v+1, inf);
dp[0] = 0;

for(int i=0; i<n; i++){
    for(int j = v-value[i]; j >= 0; j--){
        dp[j + value[i]] = min(dp[j + value[i]], dp[j] + weight[i]);
    }
}

for(int i=v; i>=0; i--){
    if(dp[i] <= k){
        res = i; // expected result
        break;
    }
}