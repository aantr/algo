#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

signed solve() {

	int m;
	if (!(cin >> m)) return 1;
	int n = 1 << m;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (m == 1) {
		cout << 2 << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= n / 2) {
			a[i] = n - 1 - a[i];
		}
	}

	int ans = n * (n + 1) / 2;
	vector<int> used(n);
	int sz = 0;
	for (int i = 0; i < n; i++) {
		used.assign(n, 0);
		sz = 0;
		for (int j = i; j < n; j++) {

			used[a[j]] ^= 1;
			sz += (used[a[j]] ? 1 : -1);
			
			if ((j - i + 1) % 4 == 0 && sz == 0){
				ans--;
			}

		}
	}

	cout << ans << "\n";

	return 0;

}

signed main() {
	int t = 1e9;
	while (t --> 0) {
		if (solve()) break;
	}
}