struct segtree {
    ll size;
    vector<ll>operations,sums;
    ll NO_OP = inf;
 
    ll op (ll a, ll b) {
        return a + b;
    }
 
    void apply_op (ll &a, ll b) {
        a = op(a,b);
    }
 
    void init (ll n) {
        size = 1;
        while (size<n)
            size *= 2;
        operations.assign(2*size,NO_OP);
        sums.assign(2*size,0);
    }
 
    void build (vector<ll>&v, ll x, ll lx, ll rx) {
        if (rx-lx==1) {
            if (lx<(ll)v.size())
                sums[x] = v[lx];
            return;
        }
        ll mid  = (lx+rx)/2;
        build(v,2*x+1,lx,mid);
        build(v,2*x+2,mid,rx);
        sums[x] = (sums[2*x+1]+sums[2*x+2]);
    }
 
    void build (vector<ll>&v) {
        build(v,0,0,size);
    }
 
    void propagate (ll x, ll lx, ll rx) {
        if (rx-lx==1 || operations[x]==NO_OP)
            return;
        ll mid = (lx+rx)/2ll;
        apply_op(operations[2*x+1],operations[x]);
        apply_op(operations[2*x+2],operations[x]);
        apply_op(sums[2*x+1],operations[x]*(mid-lx));
        apply_op(sums[2*x+2],operations[x]*(rx-mid));
        operations[x] = NO_OP;
    }
 
    void modify(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        propagate(x,lx,rx);
        if (lx>=r || rx<=l)
            return;
        if (lx>=l && rx<=r) {
            apply_op(operations[x],val);
            apply_op(sums[x],val*(rx-lx));
            return;
        }
        ll mid = (lx+rx)/2;
        modify(l,r,val,2*x+1,lx,mid);
        modify(l,r,val,2*x+2,mid,rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }
 
    void modify(ll l, ll r, ll val) {
        modify(l,r,val,0,0,size);
    }
 
    ll get (ll l, ll r, ll x, ll lx, ll rx) {
        propagate(x,lx,rx);
        if (lx>=r || rx<=l) 
            return 0;
        if (lx>=l && rx<=r)
            return sums[x];
        ll mid = (lx+rx)/2ll;
        return get(l,r,2*x+1,lx,mid)+get(l,r,2*x+2,mid,rx);
    }
 
    ll get(ll l, ll r) {
        return get(l,r,0,0,size);
    }
};