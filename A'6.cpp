#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<array<int, 3>> q;

void read(){
    cin>>n>>m;
    for (int i= 0;i<m;i++){
        cin>>q[i][0]>>q[i][1]>>q[i][2];
        q[i][0]--;q[i][1]--;
    }
}

void solve(){

    

}

signed main(){
    int t=1;
    // cin>>t;
    while (t--){
        read();
        solve();
    }
}