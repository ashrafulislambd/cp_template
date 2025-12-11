// Use this method inside general purpose segment tree
// it will return a persistent clone within O(log N) extra time and space
Node& persistentClone(int L, int R, int b, int c) {
    if (R <= lo || hi <= L) return *this;
    if (L <= lo && hi <= R) {
        Node* newNode = new Node(lo, hi);
        newNode->val = val;
        newNode->mx = mx;
        newNode->mn = mn;
        newNode->mup = mup;

        if(newNode->mup==make_pair(inf, inf))
            newNode->mup = {b, c};
        else {
            newNode->mup = {b*newNode->mup.first, b*newNode->mup.second+c};
        }
        if(b > 0) {
            newNode->mn = b*mn + c;
            newNode->mx = b*mx + c;
        } else {
            newNode->mn = b*mx + c;
            newNode->mx = b*mn + c;
        }
        newNode->val = b*val + (hi-lo)*c;
        newNode->l = l;
        newNode->r = r;
        return *newNode;
    }
    else {
        push();
        Node* newL = &l->persistentClone(L, R, b, c);
        Node* newR = &r->persistentClone(L, R, b, c);
        Node* newNode = new Node(lo, hi);
        newNode->val = val;
        newNode->mx = mx;
        newNode->mn = mn;
        newNode->mup = mup;
        newNode->l = newL;
        newNode->r = newR;

        newNode->val = newL->val + newR->val;
        newNode->mn = min(newL->mn, newR->mn);
        newNode->mx = max(newL->mx, newR->mx);
        return *newNode;
    }
}