int fac[MAX]; // set max
 
void pre() {
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2; i<MAX; i++) {
        fac[i] = (fac[i-1]*i)%MOD;
    }
}