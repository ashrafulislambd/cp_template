vector<bool> sieve(int n) {
    vector<bool> primes(n + 1, true);
 
    primes[0] = primes[1] = false;
 
    for(int i=2; i*i<=n; i++) {
        if(primes[i]) {
            for(int j =i*i; j<=n; j+=i)
                primes[j] = false;
        }
    }
    
    return primes;
}
 
vector<int> primes;
 
void init() {
    vector<bool> sv = sieve(1e8);
    for(int i=1; i<sv.size(); i++) {
        if(sv[i])
            primes.pb(i);
    }
}