typedef struct Query {
    int l,r,id,lc;
    bool operator < (const Query& x) const {
        if(l/B == x.l/B) return ((l/B)&1) ? r>x.r : r<x.r;
        return l/B < x.l/B;
    }
} Query;

//movement
while(r < R) add_r(++r);
while(l >= L) add_l(--l);
while(l < L-1) rem_l(l++);	
while(r > R) rem_r(r--);