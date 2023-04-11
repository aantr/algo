#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    std::vector<int> a;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i]) a.push_back(i);
    if (a.size() % 2 != 0) {
        cout << -1 << '\n';
        return;
    }
    if (!a.size()) {
        cout << 0 << "\n";
        return;
    }
    if (a.size() == 2) {
    	if (a[0] + 1 != a[1]){
    		cout << y << "\n";
    		return;
    	}
        if (y * 2 > x) {
            cout << x << "\n";
        } else {
        	if (a[0] >= 2 || (n - 1 - a[1]) >= 2) {
        		cout << y * 2 << "\n";
        	} else {
        		cout << x << "\n";
        	}
        }

    } else {
        cout << y * a.size() / 2 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}