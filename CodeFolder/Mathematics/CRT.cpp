int extended_gcd(int a, int b, int &x, int &y) {
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// returns {r, md}, or {-1, -1} if no solution
// x % a[i] = m[i] for i from 1 to n. find x
pair<int, int> CRT(vector<int>& a, vector<int>& m) {
    int r = a[0], md = m[0];

    for(int i=1; i < a.size(); i++){
        int x, y;
        int g = extended_gcd(md, m[i], x, y);

        if ((a[i] - r) % g != 0)
            return {-1, -1};   // impossible

        int lcm = md / g * m[i];
        int k = ((a[i] - r) / g % (m[i] / g) + (m[i] / g)) % (m[i] / g);
        k = (k * x) % (m[i] / g);

        r = (r + md * k) % lcm;
        if (r < 0) r += lcm;

        md = lcm;
    }
    // the solutions are x = r + i*mod
    return {r, md};
}