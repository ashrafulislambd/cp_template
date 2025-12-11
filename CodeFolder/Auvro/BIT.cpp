//Binary Indexed Tree:
class BIT{
private:
    int n;
    vector<int> tree;
    vector<int> input;

public:
    BIT(int sz){ 
        tree.assign(sz+1, 0); 
        input.assign(sz+1, 0); 
        n = sz; 
    }

    void insert(int i, int x){
        input[i] = x;
        while(i <= n){
            tree[i] += x;
            i += i&(-i);
        }
    }

    void update(int i, int val){
        input[i] += val;
        while(i <= n){
            tree[i] += val;
            i += i&(-i);
        }
    }

    int get_sum(int i, int j){
        int sum1 = 0, sum2 = 0;
        int it1 = i-1, it2 = j;

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

    int& operator[] (int i){ return input[i]; }
};