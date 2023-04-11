#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define TIME (double) clock() / CLOCKS_PER_SEC
// #define int ll
#define all(x) x.begin(), x.end()

int solve() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> pos(10000);
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        temp.push_back(a[i]);
        // pos[a[i]].push_back(i);
    }
    sort(all(temp));
    temp.resize(unique(all(temp)) - temp.begin());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(temp), a[i]) - temp.begin();
        pos[a[i]].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x = lower_bound(all(temp), x) - temp.begin();
        y = lower_bound(all(temp), y) - temp.begin();
        int mx = 0;
        for (int j = 1; j < n; j++) {
            mx = max(mx, (int)(lower_bound(all(pos[x]), j) - pos[x].begin()) * 
                           (int)(pos[y].end() - lower_bound(all(pos[y]), j)) );
            // cout << (lower_bound(all(pos[y]), j) - pos[y].begin()) << " ";
        }
        cout << mx << "\n";
    }
    return 1;

}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1e9;
    // cin >> t;
    while (t--) {
        if (solve()) {
            break;
        }
    }
    cerr << "Time: " << TIME << "\n";
}
