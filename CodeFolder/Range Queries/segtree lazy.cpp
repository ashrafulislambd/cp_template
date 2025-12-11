class SegmentTree {
    LL n;
    VI tree, lazy;
    LL merge(LL a, LL b) {
        return a + b;
    }

public:
    SegmentTree(LL size) {
        n = size;
        tree.assign(n << 2, 0);
        lazy.assign(n << 2, 0);
    }

    void build(LL u, LL l, LL r, VI &v) {
        if (l == r) {
            tree[u] = v[l];
            return;
        }
        LL m = l + ((r - l) >> 1);
        LL lc = u << 1, rc = lc | 1;
        build(lc, l, m, v);
        build(rc, m + 1, r, v);
        tree[u] = merge(tree[lc], tree[rc]);
    }

    void propagate(LL u, LL l, LL r) {
        if (lazy[u] != 0) {
            tree[u] += lazy[u] * (r - l + 1);
            if (l != r) {
                LL lc = u << 1, rc = lc | 1;
                lazy[lc] += lazy[u];
                lazy[rc] += lazy[u];
            }
            lazy[u] = 0;
        }
    }

    void update(LL u, LL l, LL r, LL ql, LL qr, LL val) {
        propagate(u, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            lazy[u] += val;
            propagate(u, l, r);
            return;
        }
        LL m = l + ((r - l) >> 1);
        LL lc = u << 1, rc = lc | 1;
        update(lc, l, m, ql, qr, val);
        update(rc, m + 1, r, ql, qr, val);
        tree[u] = merge(tree[lc], tree[rc]);
    }

    LL query(LL u, LL l, LL r, LL ql, LL qr) {
        propagate(u, l, r);
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[u];
        LL m = l + ((r - l) >> 1);
        LL lc = u << 1, rc = lc | 1;
        return merge(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
    }
};
