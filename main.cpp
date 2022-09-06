#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

mt19937 rnd(1234);

void solve(){

    int n;
    cin>>n;
    n*=2;
    string s;
    cin>>s;

    std::vector<int> p(n), nul;
    p[0]=1;
    int cnt = 0;
    cout<<1<<" ";
    for (int i = 1;i<n;i++) p [i] = p[i - 1] + (s[i]=='(' ? 1 : -1), cnt += p[i] == 0, cout<<p[i]<<" "; cout<<"\n";

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