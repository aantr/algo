#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int solve(){

    int n;
    if (!(cin>>n))return 1;
    vector<int> ans(n);
    for (int i=n-1;i>0;i-=2){
        ans[i] = i;
        ans[i - 1] = i + 1;
    }
    if (n % 2 == 1){
        ans[0] = 1;
    }
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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