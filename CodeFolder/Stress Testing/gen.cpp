#include<bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a , ll b){
    if(a>b) return 0;
    return a +rng()%(b-a+1);
}

void perm(ll n) {
    int x;
    map<int, int> exists;
    for(int i=1; i<=n; i++) {
        tryagain:;
        x = random(1, n);
        if(exists[x]) {
            goto tryagain;
        }
        cout << x << " ";
        exists[x]++;
    }
    cout << endl;
}

int main(){
    cout << 1 << endl;
    map<int, int> exists;
    int n = random(2, 10);
    cout << n << endl;
    perm(n);
    perm(n);
}