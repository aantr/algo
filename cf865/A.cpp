#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll

void solve() {

	int n, q;
	cin >> n >> q;
	std::vector<int> a(n), pref(n + 1), suf(n + 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	pref[0] = 1e18;
	suf[0] = 1e18;
	int SUM = accumulate(a.begin(), a.end(), 0ll);

	for (int i = 0; i < n; i++) {
		pref[i + 1] = min(pref[i], a[i] - i);
		suf[i + 1] = min(suf[i], a[n - 1 - i]);
	}

	for (int  _ = 0; _ < q; _++) {
		int x;
		cin >> x;
		if (n == 1) {
			if (x % 2 == 0) {
				cout << a[0]-x / 2 << " ";
			} else {
				cout << a[0]-x / 2 + x<< " ";
			}
			continue;
		}
		int ans;
		if (x < n) {
			ans = min(pref[x] + x, suf[n - x]);
		} else {
			if ((x - n) % 2 == 0) {
				int mn = pref[n] + x;
				int sum = SUM + (2 * x -n + 1) * n / 2;
				int v = sum - mn * n;
				x -= v * 2;
				x -= n;
				x/=2;
				if (x > 0) {
					ans = mn - ceil((ld)x / (ld)n);
				} else {
					ans = mn;
				}
			} else {
				int mn = min(pref[n - 1] + x, a[n - 1]);
				int sum = SUM + (2 * x - n + 2) * (n - 1) / 2;
				int v = sum - mn * n;
				x -= v * 2;
				x -= n - 1;
				x/=2;
				if (x > 0) {
					ans = mn - ceil((ld)x / (ld)n);
				} else {
					ans = mn;
				}
			}
		}

		cout << ans << " ";
	}
	cout << "\n";

}

signed main() {
	int t = 1;
	// cin >> t;
	while (t--) solve();
}