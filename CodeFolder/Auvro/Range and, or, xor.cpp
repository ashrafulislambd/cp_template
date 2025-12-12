int one_count(int n, int i){
    int b = 1LL << (i+1);
    return (n+1)/b * b/2 + max(0LL, ((n+1) % b) - b/2);
}

void solve(int tc){
    int l, r, AND = 0, OR = 0, XOR = 0;
    cin>>l>>r;
    
    for(int i=0; i<61; i++){
        int cnt = one_count(r, i) - one_count(l-1, i);

        if(cnt % 2 == 1)
            XOR = XOR | (1LL << i);
        if(cnt)
            OR = OR | (1LL << i);
        if(cnt == r - l + 1)
            AND = AND | (1LL << i);
    }

    cout<<AND<<" "<<OR<<" "<<XOR<<"\n";
}