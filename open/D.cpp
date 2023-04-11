#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){

    int n, m;
    cin >> n >> m;

    if (n <= 1000 && m <= 1000) {
        vector<int> ans(n);
        vector<int> cur(n, 1);
        for (int i = 0; i < m; i++) {
            char c;
            int l, r;
            cin >> c >> l >> r;
            for (int j = l - 1; j < r; j++) {
                cur[j] = int(c == '-');
            }
            for (int j = 0; j < n; j++) {
                ans[j] += cur[j];
            }

        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }

        return 1;
    }

    vector<int> cur(n, 1);
    std::vector<std::vector<int>> a(n, vector<int> {0});
    for (int i = 0; i < m; i++) {
        char c;
        int l, r;

        cin >> c >> l >> r;
        l--;
        if (c == '+') {
            if (cur[l] == 1) {
                cur[l] = 0;
                a[l].push_back(i);
            }
        } else if (c == '-') {
            if (cur[l] == 0) {
                cur[l] = 1;
                a[l].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        // cout << 1 << endl;
        int tot = 0;
        a[i].push_back(m);
        for (int j = 0; j < a[i].size() - 1; j+=2) {
            tot += a[i][j + 1] - a[i][j];
        }
        cout << tot << " ";
    }

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