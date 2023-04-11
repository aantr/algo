#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

void solve () {

	int n, m, k;
	cin >> n >> m >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int mn = 1e9;
	for (int mask = 0; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) > m) continue;
		vector<int> res, r;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) r.push_back(a[i]);
			else res.push_back(a[i]);
		}
		for (int i : r) res.push_back(i);
		for (int i = 0; i < n; i++) {
			if ((i + 1) % k != 0) ans += res[i];
		}
		mn = min(mn, ans);
	}

	cout << mn << endl;

}

signed main () {
	int t = 1;
	while (t --> 0) {
		solve();
	}
}