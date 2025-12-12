int ncr(int n, int r) {
    if(r>n) return 0;
    int d = (fac[n-r] * fac[r]) % MOD;
    int ind = inv(d);
    //dbg(n, r, (fac[n]*ind)%MOD);
    return (fac[n]*ind)%MOD;
}