#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve() {
    int x;
    if (!(cin >> x)) return 1;
    vector<array<int, 2>> ans;
    int K = 1e5;
    for (int i = 1; i < K; i++) {
        int full = x + i * 2;
        // full = (m + 1) * n + (n + 1) * m
        // f = mn + n + (n+1)*m, f = m(n + n + 1)+n, m = (f-n) / (n + n + 1)
        int M = (full - i) / (i + i + 1);
        if (i * (M + 1) + ((i + 1) * M) == full && M > i) ans.push_back({i, M});
    }

    for (int j = 1; j < K; j++) {
        int full = x + j * 2 - 1;
        // f = (m - 1) * n + (n - 1) * m, f = (m-1)*n + mn - m, f = n(m+m-1)-m, n = (f+m)/(m+m-1)
        int N = (full - j) / (j * 2 + 1);
        if (N * (j + 1) + (N + 1) * j == full && N >= j) ans.push_back({N, j});
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }

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
