
class SortedArray {
    ordered_multiset arr;
public:
    long long size() { return arr.size(); }
    void operator += (long long x) { arr.insert(x); } 
    long long operator < (long long x) { return arr.order_of_key(x); }
    long long operator <= (long long x) { return arr.order_of_key(x+1); }
    long long operator > (long long x) { return arr.size() - arr.order_of_key(x+1); }
    long long operator >= (long long x) { return arr.size() - arr.order_of_key(x); }
    long long LR(long long l, long long r) { return max((*this <= r) - (*this < l), 0LL); }
    long long lR(long long l, long long r) { return LR(l+1, r); }
    long long Lr(long long l, long long r) { return LR(l, r-1); }
    long long lr(long long l, long long r) { return LR(l+1, r-1); }
    long long operator [] (long long i) { return *arr.find_by_order(i); }
};
