#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){

    int n, m;
    cin >> n >> m;
    cout << min(2ll, n) << " " << min(2ll, m) << endl;

    return 0;

}

signed main(){
    int t = 1e9;
    cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}