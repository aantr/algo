#include <bits/stdc++.h>

using namespace std;

const int K = 300;

void solve() {
    int n, m;
    cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> gr(n);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        for (int j : gr[i]) {
            cnt += a[i] != a[j];
        }
    }

    cnt /= 2;

    for (int i = 0; i < n; i++) {
        sort(gr[i].begin(), gr[i].end(), [&](int a, int b) { return gr[a].size() < gr[b].size(); });
    }

    vector<map<int, int>> neighbors(n);
    for (int i = 0; i < n; i++) {
        if (gr[i].size() >= K) {
            for (int j : gr[i]) {
                if (gr[j].size() < K) {
                    neighbors[i][a[j]]++;
                }
            }
        }
    }
    int q;
    cin >> q;

    while (q--) {
        int c, x;
        cin >> c >> x;
        c--;
        if (gr[c].size() < K) {
            for (int j : gr[c]) {
                if (a[j] != a[c]) {
                    cnt--;
                }
                if (a[j] != x) {
                    cnt++;
                }
            }
            for (int i = (int)gr[c].size() - 1; i >= 0; i--) {
                if (gr[gr[c][i]].size() < K) {
                    break;
                }
                neighbors[gr[c][i]][a[c]]--;
                neighbors[gr[c][i]][x]++;
            }
        } else {
            for (int i = (int)gr[c].size() - 1; i >= 0; i--) {
                if (gr[gr[c][i]].size() < K) {
                    break;
                }
                if (a[gr[c][i]] != a[c]) {
                    cnt--;
                }
                if (a[gr[c][i]] != x) {
                    cnt++;
                }
            }
            cnt += neighbors[c][a[c]] - neighbors[c][x];
        }

        a[c] = x;
        cout << cnt << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    cerr << "end." << endl;
}
