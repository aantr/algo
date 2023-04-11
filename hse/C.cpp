#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define TIME (double) clock() / CLOCKS_PER_SEC
#define int ll
#define all(x) x.begin(), x.end()

const int inf = 1e18;

void solve() {

    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!j) dp[i + 1][j] = dp[i][j + 1];
            else dp[i + 1][j] = max(dp[i][j - 1] + a[i], dp[i][j + 1]);
        }
    }
    int bal = 0;
    string res;
    for (int i = n - 1; i >= 0; i--) {
        if (bal && dp[i][bal - 1]  + a[i] == dp[i + 1][bal]) {
            res+= '(';
            bal--;
        } else {
        res+= ')';
            bal++;
        }
    }
    reverse(all(res));
    cout <<res <<  "\n";

}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    cerr << "Time: " << TIME << "\n";
}
