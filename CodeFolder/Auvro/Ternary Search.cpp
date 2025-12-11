//Ternary Search:
int func(int mid, vector<pair<int, int>> v){
    int back = 0, front = 0;
 
    for(int i=0; i<v.size(); i++){
        if(front + mid < v[i].first || back - mid > v[i].second)
            return 0;
 
        front = min(v[i].second, front + mid);
        back = max(v[i].first, back - mid);
    }
 
    return 1;
}

int tsearch(vector<pair<int, int>> v, int mx){
    int left = 0, right = mx + 5, mid = 0;

    while(right - left > 5){
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if(func(mid1, v) < func(mid2, v))
            left = mid1; 
        else 
            right = mid2; 
    }

    
    for(int i=left; i<=right; ++i){
        if(i < 0)
            continue;
        if(func(i, v) == 1) 
           return i;
    }

    return mid;
}
