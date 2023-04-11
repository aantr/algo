#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = a[i] == 0;
	}

	fenwick f(a);

	int m;
	cin >> m;
	while (m--) {
		char c;
		cin >> c;
		if (c == 'u') {
			int i, v;
			cin >> i >> v;
			i--;
			f.add(i, (v == 0) - (a[i]));
			a[i] = v == 0;
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			l--;
			int K = f.get(l);
			k += K;
			int L = 0, R = r;
			while (R - L > 1) {
				int m = L + R >> 1;
				// cout << L << " " << R << " " << f.t[m] << endl;
				if (f.get(m) < k) {
					L = m;
				} else {
					R = m;
				}
			}
			if (f.get(R) != k) cout << -1 << " ";
			else cout << R << " ";
		}
	}

}

signed main() {
	int t = 1;
	while (t--	) solve();
}