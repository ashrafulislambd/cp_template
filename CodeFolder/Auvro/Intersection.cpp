//Interval Intersection and Union:
// intersection size
int intersect(int l1, int r1, int l2, int r2){
    int low = max(l1, l2);
    int high = min(r1, r2);
    return max(0LL, high-low+1);
}

// intersection range
pair<int, int> intersect(int l1, int r1, int l2, int r2){
    int low = max(l1, l2);
    int high = min(r1, r2);

    if(low > high) 
        return {-1, -1};

    return {low, high};
}

// union size
int unite(int l1, int r1, int l2, int r2){
    int low = min(l1, l2); 
    int high = max(r1, r2);

    return high-low+1;
}

// union range
pair<int, int> unite(int l1, int r1, int l2, int r2){
    int low = min(l1, l2); 
    int high = max(r1, r2);

    return {low, high};
}
