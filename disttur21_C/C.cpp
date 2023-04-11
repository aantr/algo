#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){
    
    int m, n;
    cin >> n >> m;

    std::vector<int> a(n + m - 1), b(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) cin >> a[i];
    for (int i = 0; i < n + m - 1; i++) cin >> b[i];

    if (m > n) {
        swap(n, m);
        swap(a, b);
        reverse(a.begin(), a.end());
    }
    vector<int> p0(n + m), p1(n + m);
    for (int i = 0; i < n + m - 1; i++) {
        p0[i + 1] = p0[i];
        p1[i + 1] = p1[i];
        if (i % 2 == 0) p0[i + 1] += a[i];
        else p1[i + 1] += b[i];
    }
    vector<array<int, 2>> need(n + m - 1); // need 1

    int l = m - 1, r = m - 1;
    int v1 = -1, v2 = 1;
    for (int i = 0; i < n + m - 1; i++) {
        need[i] = {l, r};
        if (l == 0) v1 *= -1;
        if (r == n + m - 1 - 1) v2 *= -1;
        l += v1;
        r += v2;
    }

    if (m == 1) {
        int ans = 0;
        for (int i = 0; i < n + m - 1;i ++) {
            ans += min(a[i], b[i]);
        }
        cout << ans << "\n";
        return 1;
    }
    if (m <= 10 && n <= 10){
    
        int mn = 1e18;
        for (int mask = 0; mask < 1 << (n + m - 1); mask++){
            int ans = 0;
            vector<int> d1(n + m - 1);
            for (int i = 0; i < n + m - 1; i++) {
                if (mask >> i & 1) {
                    for (int k = need[i][0]; k <= need[i][1]; k+=2) {
                        d1[k]=1;
                    }
                } else {
                    ans += b[i];
                }
            }
            for (int i = 0; i < n + m - 1; i++) {
                if (d1[i]) ans += a[i];
            }
            if (mn >= ans) {
                mn = ans;
                // cout << mask << '\n';
            }
        }

        cout << mn << endl;
        return 1;
    }
    
    int mn = min(accumulate(a.begin(), a.end(), 0ll), accumulate(b.begin(), b.end(), 0ll));
    for (int q = 0; q < 2; q++) {
        int d1 = 0;
        int cur = 0;
        for (int i = 0; i < n; i+=2) {
            cur += b[i] + b[b.size() - 1 - i];
            if (i == n - 1) cur >>= 1;
            int n1;
            if (need[i][0] % 2 == 0) {
                n1 = p0[need[i][1] + 1] - p0[need[i][0]];
            } else {
                n1 = p1[need[i][1] + 1] - p1[need[i][0]];
            }
            d1 = min(d1, n1 - cur);
        }
        int d2 = 0;
        cur = 0;
        for (int i = 1; i < n; i+=2) {
            cur += b[i] + b[b.size() - 1 - i];
            if (i == n - 1) cur >>= 1;
            int n1;
            if (need[i][0] % 2 == 0) {
                n1 = p0[need[i][1] + 1] - p0[need[i][0]];
            } else {
                n1 = p1[need[i][1] + 1] - p1[need[i][0]];
            }
            d2 = min(d2, n1 - cur);
        }
        mn = min(mn, accumulate(b.begin(), b.end(), 0ll) + d1 + d2);
        swap(a, b);
        // cout << d1 << " " << d2 << endl;
    }
    cout << mn << "\n";

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