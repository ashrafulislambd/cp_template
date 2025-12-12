int sqroot(int n) {
    if(n < 2)
        return n;

    int l = 1, r = n/2, ans = 1;

    while(l <= r){
        int mid = l + (r - l)/2;

        if(mid <= n/mid){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return ans;
}