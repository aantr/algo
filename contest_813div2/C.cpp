#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int solve(){

    int n;
    if (!(cin>>n)) return 1;
    vector<int> a(n);
    vector<int> mx_idx(n + 1);
    vector<int> used(n + 1);
    for (int i=0;i<n;i++)cin>>a[i], mx_idx[a[i]] = i;
    
    int mx = -1;
    for (int i=0;i<n-1;i++){
        if (a[i] > a[i + 1]) mx = i;
    }
    int last = -1;
    while (last < mx){
        int MX = -1;
        for (int i = last + 1;i<= mx;i++){
            
            MX = max(MX, mx_idx[a[i]]);

            if (!used[a[i]]){
                used[a[i]] = 1;
                a[i] = 0;

            }
        }
        last = mx;
        mx = MX - 1;
    }

    cout<<accumulate(used.begin(), used.end(), 0)<<"\n";
    return 0;
}

/*

1 2 3
1 3 2

*/

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1e9;
    cin>>t;
    while (t--){
        if (solve())break;
    }
    cerr<<"time: "<<(double)clock() / (double)CLOCKS_PER_SEC<<"\n";
}