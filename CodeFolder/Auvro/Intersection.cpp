//Interval Intersection and Union:
int intersect(int l1, int r1, int l2, int r2){
    int low = max(l1, l2);
    int high = min(r1, r2);
    return max(0LL, high-low+1);
}

int unite(int l1, int r1, int l2, int r2){
    int low = min(l1, l2); 
    int high = max(r1, r2);

    return high-low+1;
}
