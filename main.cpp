#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll

const int maxn = 2e5 + 1;
const int mod = 1e9 + 7;
int dp[maxn][64];

void solve() {
    
    int n, k;
    cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) {
            dp[i + 1][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j & a[i]] += dp[i][j];
            dp[i + 1][j] %= mod;
            dp[i + 1][j & a[i]] %= mod;
        }
        dp[i + 1][a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        if (__builtin_popcount(i) == k) {
            ans = (ans + dp[n][i]) % mod;
        }
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    #ifdef ON_PC
    // freopen("input.txt", "r", stdin);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();
    cerr << "[Time: " << (ld) clock() / CLOCKS_PER_SEC << " seconds]\n";


}