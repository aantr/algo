#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define TIME (double) clock() / CLOCKS_PER_SEC

// #define int ll

int solve(){

    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int N = i;
        int ok = 1;
        while (N) {
            if (N % 10 == x || N % 10 == y) {

            } else {
                ok = 0;
            }
            N /= 10;
        }
        ans += ok;
    }

    cout << ans << "\n";

    return 1;
}

signed main(){
    int t = 1e9;
    // cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}