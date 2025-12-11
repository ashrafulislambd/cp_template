// maximum and minimum subarray sum
int maxs(vector<int> &a, int n)
{
    if(n == 0)
        return 0;

    int maxn = LONG_LONG_MIN, curr = 0;

    for(auto p:a) {
        curr = max(p, curr + p); 
        maxn = max(maxn, curr);   
    }

    if(maxn <= 0)
        return 0;
    return maxn;
}

int mins(vector<int> &a, int n){
    if(n == 0)
        return 0;

    int minn = LONG_LONG_MAX, curr = 0;

    for(auto p:a) {
        curr = min(p, curr + p); 
        minn = min(minn, curr);   
    }

    if(minn >= 0)
        return 0;
    return minn;
}