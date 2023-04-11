#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define TIME (double) clock() / CLOCKS_PER_SEC
#define all(x) x.begin(), x.end()
#define int ll

const int inf = 1e9 + 7;

ostream& operator<<(ostream& s, vector<int> a) {
    for (auto i : a) s << i << " ";
    return s;
}

mt19937 rnd(1234);

vector<int> get(std::vector<int> a) {
    vector<int> res = a;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[i - 1]) {
            res[i - 1] ++;
        }
    }
    return res;
}

int solve() {
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 1);
    vector<int> b(n);
    for (int i = 0; i < m; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        l--;
        if (c == '+') {
            for (int i = l; i < r; i++) {
                a[i] = 0;
            }
        } else {
            for (int i = l; i < r; i++) {
                a[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            b[i] += a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 1;
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        if (solve()) {
            break;
        }
    }
    cerr << "Time: " << TIME << "\n";
}
