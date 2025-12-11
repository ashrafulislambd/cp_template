// nearest smaller element
void build(int input[], int pre[], int n, const string &op)
{
    deque<int> d;

    for(int i=1; i<=n; i++){
        int x = input[i];
        
        while(1){
            if(d.size() == 0){
                pre[i] = -1;
                d.push_back(x);
                break;
            }

            if(op == "pre"){
                if(d.back() < x){
                    pre[i] = d.back();
                    d.push_back(x);
                    break;
                }
                else
                    d.pop_back();
            }
            else{
                if(d.front() < x){
                    pre[i] = d.front();
                    d.push_front(x);
                    break;
                }
                else
                    d.pop_front();
            }
        }
    }
}
