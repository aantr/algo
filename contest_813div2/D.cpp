#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
// #define int ll

int solve(){

    int n;
    if (!(cin>>n)) return 1;
    int k;
    cin>>k;
    vector<int> a(n);
    for (int i=0;i<n;i++)cin>>a[i];
    if (k == n){
        cout<<"1000000000\n";
        return 0;
    }

    int ans = -inf;
    ordered_set <array<int, 2>, null_type> s;
    for (int i=0;i<n;i++)s.insert({a[i] * 2, i});

    for (int i=0;i<n-1;i++){

        s.erase({a[i] * 2, i});
        s.erase({a[i + 1] * 2, i + 1});
        s.insert({a[i], (int)1e9 + 1});
        s.insert({a[i + 1], (int)1e9 + 2});

        ans = max(ans, (*s.find_by_order(k))[0]);

        s.insert({a[i] * 2, i});
        s.insert({a[i + 1] * 2, i + 1});
        s.erase({a[i], (int)1e9 + 1});
        s.erase({a[i + 1], (int)1e9 + 2});
    }

    cout<<min((int)1e9, ans)<<endl;

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