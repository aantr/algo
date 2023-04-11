#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;

void solve() {

	int k1 = 1, k2 = 1;
	std::vector<int> a(maxn);
	a[1] = 1;
	for (int i = 0; i < 5; i++) {
		a[k1 + k2] = 1;
		int t = k1 + k2;
		k1 = k2;
		k2 = t;
	}
	int n; cin >> n;
	while (n--) {
		int x;
		cin >> x;
		cout << (a[x] ? "Yes" : "No") << "\n";
	}

}

signed main() {
	int t = 1;
	while (t--) solve();
}