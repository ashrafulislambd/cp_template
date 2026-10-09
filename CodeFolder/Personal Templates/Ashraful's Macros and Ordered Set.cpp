
/*
Author: Md. Ashraful Islam
Copyright @ All Rights Reserved
*/

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define pll pair<long long, long long>
#define asort(a) sort(a.begin(), a.end()) 
#define arsort(a,n) sort(a, a+n)
#define MAX 2000005
#define MOD 998244353
#define faster {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define endl "\n"
#define pii pair<int, int>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;
typedef vector<int> vi;

//using namespace __gnu_pbds;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<long long, long long>, null_type,less<pair<long long, long long>>, rb_tree_tag,tree_order_statistics_node_update >
#define ordered_multiset tree<unsigned long long, null_type,less_equal<unsigned long long>, rb_tree_tag,tree_order_statistics_node_update >


#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) {/*temon kichu na*/}
#endif

#define int long long

void solve() {
	$1	
}

signed main() {
    faster;
    bool NO_TEST_CASE = true;
    bool PRll_CASE = false;
    bool INLINE_CASE = true;

    ll T;
    if(NO_TEST_CASE) {
        T = 1;
    } else {
        cin >> T;
    }
    for(ll t=1; t<=T; t++) {
        if(PRll_CASE) {
            cout << "Case " << t << ": "; 
            if(!INLINE_CASE) {
                cout << endl;
            }
        }
        solve();
    }
    return 0;
} 
