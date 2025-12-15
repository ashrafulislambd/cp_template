class BIT{
private:
    int n;
    vector<int> tree;

public:
    BIT(vector<int> &v){
        n = v.size(); 
        tree.assign(n+1, 0); 
        
        for(int i=0; i<n; i++){
            int it = i+1;
            while(it <= n){
                tree[it] += v[i];
                it += it & (-it); 
            }
        }
    }

    void affine(int i, int val){
        i++;
        while(i <= n){
            tree[i] += val;
            i += i&(-i);
        }
    }

    int get_sum(int i, int j){
        int sum1 = 0, sum2 = 0;
        int it1 = i, it2 = j+1;

        //sum from index 1 to i-1
        while(it1 > 0){
            sum1 += tree[it1];
            it1 -= it1&(-it1);
        }

        //sum from index 1 to j
        while(it2 > 0){
            sum2 += tree[it2];
            it2 -= it2&(-it2);
        }

        //sum from i to j
        return (sum2 - sum1);
    }

    void update(int i, int val){
        affine(i, val - get_sum(i, i));
    }
};