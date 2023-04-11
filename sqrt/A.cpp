#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve() {
    int n, s;
    if (!(cin >> n)) return 1;
    cin >> s;
    function<int(int, int)> f = [&](int b, int n){
        if (n < b) return n;
        return f(b, n / b) + n % b;
    };
    if (n == s) {
        cout << n + 1 << "\n";
        return 0;
    } else {
        int mn = LLONG_MAX;
        for (int b = 2; b < 4e5; b++) {
            if (f(b, n) == s) {
                mn = min(mn, b);
                break;
            }
        }
        for (int d = 4e5 ; d > 0; d--) {
            int d1 = s - d;
            int b = (n - d1) / d;
            if (b > 1 && d1 >= 0 && f(b, n) == s) {
                mn = min(mn, b);
                break;
            }
        }
        if (mn < LLONG_MAX) {
            cout << mn << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}

signed main() {
    int t = 1e9;
    // cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr << "Time: " << TIME << endl;
}
