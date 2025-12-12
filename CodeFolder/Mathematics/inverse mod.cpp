int inv(int a, int m = MOD) {
    return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}