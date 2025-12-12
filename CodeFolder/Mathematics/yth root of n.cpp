int power(int n, int x){
    int base = n;

    for(int i=1; i<x; i++){
        if(n >= inf/base)
            return inf;
        n *= base;
    }

    return n;
}

int root(int n, int y) {
    if(n < 2)
        return n;

    int l = 1, r = n/2, ans = 1;

    while(l <= r){
        int mid = l + (r - l)/2;

        if(power(mid, y) <= n){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return ans;
}