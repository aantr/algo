#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int solve(){

    int n;
    if (!(cin>>n))return 1;
    int k;
    cin>>k;
    vector<int> a(n);
    for (int i=0;i<n;i++)cin>>a[i];
    int cnt=0;
    for (int i=0;i<k;i++) cnt+= a[i] > k;
    cout<<cnt<<"\n";
    return 0;
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1e9;
    cin>>t;
    while (t--){
        if (solve())break;
    }
    cerr<<"time: "<<(double)clock() / (double)CLOCKS_PER_SEC<<"\n";
}