#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int maxn = 1e6;
const int K = 100;
ld dp[maxn][K + 5];

int solve(){

    cout << setprecision(10) << fixed;

    dp[0][0] = 1;
    dp[0][K] = 1;

    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < K; j++) {
            ld q = (ld)j * (K - j) / ((K - 1) * K);

            dp[i][j] = q * dp[i - 1][j - 1] + q * dp[i - 1][j + 1] + ((ld) 1 - 2 * q) * dp[i - 1][j];
        }
    }

    for (int i = 0; i < K; i++) {
        cout << dp[i][1] << "\n";
    }

    ld ans = 0;
    for (int i = 1; i < maxn; i++) {
        ans += i * dp[i][1];
    }
    cout << setprecision(6) << fixed << (ld)ans << "\n";

    return 0;

}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // cin>>t;
    #ifndef ON_PC
    /*
    freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);
    */
    #endif
    while (t--){
        if (solve()) break;
    }
    cerr<<"time: "<<(double)clock() / (double)CLOCKS_PER_SEC<<"\n";
}