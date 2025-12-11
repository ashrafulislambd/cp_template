
class SegmentTree {
public:
    int *arr, *tree;
    int _size;
    SegmentTree(vector<int> v) {
        int size = v.size();
        _size = size;
        arr = new int[size+10];
        for(int i=1; i<=size; i++) {
            arr[i] = v[i-1];
        }
        tree = new int[(size+10)*4];
        build(1, 1, size);
    }

    void build(int node, int b, int e)
    {
        int left, right, mid;
        if(b == e){
             tree[node] = arr[b];
             return;
        }
        left = node*2;
        right = node*2 + 1;
        mid = (b+e)/2;
        build(left, b, mid);
        build(right, mid+1, e);
        tree[node] = min(tree[left], tree[right]);
    }

    int query(int node, int b, int e, int i, int j)
    {
        int left, right, mid;
        if(i > j)
             return INT_MAX;
        if(i == b && j == e)
             return tree[node];
        mid = (b+e)/2;
        left = 2*node;
        right = 2*node + 1;
        return min(query(left, b, mid, i, min(j, mid)), query(right, mid+1, e, max(mid+1, i), j));
    }

    int query(int l, int r) {
        return query(1, 1, _size, l, r);
    }

    void update(int node, int b, int e, int i, int newvalue)
    {
        if (i > e || i < b)
            return; 
        if (b >= i && e <= i) {
            tree[node] = newvalue;
            return;
        }
        int Left = node * 2; 
        
        int Right = node * 2 + 1;
        int mid = (b + e) / 2;
        update(Left, b, mid, i, newvalue);
        update(Right, mid + 1, e, i, newvalue);
        tree[node] = min(tree[Left], tree[Right]);
    }

    void update(int i, int val) {
        update(1, 1, _size, i, val);
    }
};
