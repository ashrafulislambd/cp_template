//Nearest Smaller Element:
/*
    Input: First line: n, q. Second line: n 
    integers a[]. Next q lines: queries where
    each query i(0<i<=n) asks to find the 
    nearest smaller element of a[i] that 
    both PRECEEDS and PROCEEDS a[i].

    Output: For each i, print the answer in
    a new line. If no answer exists, print -1.

    Constraints: 0<n<200000, 0<q<100000,
    0<a[i]<1000000

    Time Limit: 2 seconds

    Memory Limit: 256 MB

    Solution Approach: We process the input array
    a[] and store the nearest smaller elemnts for
    each i in another array. So for each query,
    we can get the answer in O(1) time after O(n)
    preprocessing.
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define mod 1000000007

void build_pre(int input[], int pre[], int n)
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

            if(d.back() < x){
                pre[i] = d.back();
                d.push_back(x);
                break;
            }
            else
                d.pop_back();
        }
    }
}

void build_post(int input[], int post[], int n)
{
    deque<int> d;

    for(int i=n; i>0; i--){
        int x = input[i];
        
        while(1){
            if(d.size() == 0){
                post[i] = -1;
                d.push_back(x);
                break;
            }

            if(d.front() < x){
                post[i] = d.front();
                d.push_front(x);
                break;
            }
            else
                d.pop_front();
        }
    }
}

signed main()
{
    int n, q;
    cin>>n>>q;

    int pre[n+1], post[n+1], input[n+1];

    for(int i=1; i<=n; i++)
        cin>>input[i];

    build_pre(input, pre, n);
    build_post(input, post, n);

    //queries
    while(q--){
        int i;
        cin>>i;
        
        if(pre[i] == -1 || post[i] == -1)
            cout<<max(pre[i], post[i])<<"\n";
        else
            cout<<min(pre[i], post[i])<<"\n";
    }

    return 0;
}
