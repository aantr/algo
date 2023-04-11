#include<bits/stdc++.h>

using namespace std;
#define int long long

const int K = 300;

void solve() {
    int n;
    cin >> n;
    vector<int> need(n);
    for (int i = 0; i < n; i++)cin >> need[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        need[i] = x - need[i];
    }
    int m;
    cin >> m;
    vector <array<int, 4>> q(m);
    for (int i = 0; i < m; i++)cin >> q[i][0] >> q[i][1] >> q[i][2] >> q[i][3], q[i][0]--, q[i][1]--;
    vector<int> idx_block(n, -1);
    for (int i = 0; i < n; i++) {
        if (need[i] <= 0)idx_block[i] = -2;
    }
    vector<int> ans(n);

    for (int i = 0; i < m; i += K) {
        vector<int> r2(n + 2);
        for (int j = i; j < min(m, i + K); j++) {
            int l = q[j][0], r = q[j][1];
            r2[l] += q[j][2];
            r2[l + 1] += -q[j][2] + q[j][3];
            r2[r + 1] += -(r - l + 1) * q[j][3] - q[j][2];
            r2[r + 2] += (r - l) * q[j][3] + q[j][2];
        }
        vector<int> r1(n + 1);
        r1[0] = r2[0];
        for (int i = 1; i < n + 1; i++)r1[i] = r1[i - 1] + r2[i];
        vector<int> add(n);
        add[0] = r1[0];
        for (int i = 1; i < n; i++) {
            add[i] += add[i - 1] + r1[i];
        }
        int cur = i;
        for (int i = 0; i < n; i++) {
            if (add[i] >= need[i] && idx_block[i] == -1) {
                idx_block[i] = 0;

                for (int W = cur; W < min(cur + K, m); W++) {
                    int l = q[W][0], r = q[W][1];
                    if (l <= i && i <= r) {
                        need[i] -= q[W][2] + q[W][3] * (i - l);
                    }
                    if (need[i] <= 0) {
                        ans[i] = W + 1;
                        break;
                    }
                }
            }
            need[i] -= add[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (idx_block[i] == -1) {
            cout << -1 << " ";
        } else if (idx_block[i] == -2) {
            cout << "0 ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << "\n";
}

signed main() {
    int t = 1;
    //cin>>t;
    while (t--) solve();
}
