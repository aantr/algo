#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define int ll

void solve() {

    int n, k, d, p;
    cin >> n >> k >> d >> p;
    int m;
    cin >> m;
    std::vector<int> lev(n);
    while (m--) {
        char c;
        int L, v;
        cin >> c >> L >> v;
        if (c == '-') {
            v *= -1;
            lev[L] += v;
        } else {
            lev[L] += v;
        }
        int ans = 0;
        vector<int> fil(n);
        
        for (int i = n - 1; i >= 0; i--) {
            int cur = lev[i];
            int l = i;
            for (int j = n - 1; j >= 0; j--) {

                if (abs(i - j) * 100 <= d * 100 + i * p) {
                    v = min(k - fil[j], cur);
                    // cout << "v: " << i << " " << j << " " << v << "\n";
                    cur -= v;
                    fil[j] += v;
                    ans += v;
                }

            }

        }
        cout << ans << "\n";
    }

}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}