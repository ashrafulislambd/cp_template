using u128 = __uint128_t;
ll modmul(ll a, ll b, ll m) {
    return (u128)a * b % m;
}
ll modpow(ll a, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e & 1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        e >>= 1;
    }
    return r;
}
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll p : {2,3,5,7,11,13,17,19,23,29,31,37})
        if (n % p == 0) return n == p;

    ll d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, ++s;

    auto check = [&](ll a) {
        if (a % n == 0) return true;
        ll x = modpow(a, d, n);
        if (x == 1 || x == n - 1) return true;
        for (ll r = 1; r < s; r++) {
            x = modmul(x, x, n);
            if (x == n - 1) return true;
        }
        return false;
    };

    for (ll a : {2LL,325LL,9375LL,28178LL,450775LL,9780504LL,1795265022LL})
        if (!check(a)) return false;
    return true;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll f(ll x, ll c, ll mod) {
    return (modmul(x, x, mod) + c) % mod;
}
ll pollard(ll n) {
    if (n % 2 == 0) return 2;
    uniform_int_distribution<ll> dist(2, n - 2);
    while (true) {
        ll x = dist(rng), y = x, c = dist(rng), d = 1;
        while (d == 1) {
            x = f(x, c, n);
            y = f(f(y, c, n), c, n);
            d = __gcd(abs(x - y), n);
        }
        if (d != n) return d;
    }
}
void factor(ll n, vector<ll> &res) {
    if (n == 1) return;
    if (isPrime(n)) {
        res.push_back(n);
        return;
    }
    ll d = pollard(n);
    factor(d, res);
    factor(n / d, res);
}
//usage (in main write this)
ll x;
cin >> x;
vector<ll>fact;
factor(x,fact);
sort(all(fact));
// the prime factors of x are now stored in the vector fact.