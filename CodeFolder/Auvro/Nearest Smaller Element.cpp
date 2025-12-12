// Returns index

void build_pre(int input[], int pre[], int n){
    vector<pair<int, int>> v;
 
    for (int i=1; i<=n; i++) {
        int x = input[i];
 
        while(1){
            if(v.empty()){
                pre[i] = -1; 
                v.push_back({x, i});
                break;
            }
 
            if(v.back().first > x){
                pre[i] = v.back().second; 
                v.push_back({x, i});
                break;
            } 
            else 
                v.pop_back();
        }
    }
}
 
void build_post(int input[], int post[], int n){
    deque<pair<int, int>> d;
 
    for(int i=n; i>0; i--){
        int x = input[i];
 
        while(1){
            if(d.empty()){
                post[i] = -1;
                d.push_front({x, i});
                break;
            }
 
            if(d.front().first < x){
                post[i] = d.front().second; 
                d.push_front({x, i});
                break;
            } 
            else 
                d.pop_front();
        }
    }
}