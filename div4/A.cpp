#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define TIME (double)clock() / CLOCKS_PER_SEC

mt19937 rnd(1234);

void solve(){

    int n;
    cin>>n;
    int cur = n;
    int ans [3]={};
    for (int i = 60;i>=0;i--){

        int after = cur - (1 << i) * 3;
        if (after == 0 || i > 0 && after > 0 && after <= ((1 << (i - 1)) * 3)){
            cur = after;
            for (int j = 0;j<3;j++)
                ans[j] += 1<<i;
        }

    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
    
}

signed main(){
    int t=1;
    cin>>t;
    #ifndef ON_PC
    /*
    freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);
    */
    #endif
    while (t--){
        solve();
    }
    cerr<<"Time: "<<double(clock()) / CLOCKS_PER_SEC<<"\n";
}