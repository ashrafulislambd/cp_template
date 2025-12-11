
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
        tree[node] = tree[left] + tree[right];
    }

    int query(int node, int b, int e, int i, int j)
    {
        int left, right, mid;
        if(i > j)
             return 0;
        if(i == b && j == e)
             return tree[node];
        mid = (b+e)/2;
        left = 2*node;
        right = 2*node + 1;
        return query(left, b, mid, i, min(j, mid)) + query(right, mid+1, e, max(mid+1, i), j);
    }

    int query(int l, int r) {
        return query(1, 1, _size, l, r);
    }
};
