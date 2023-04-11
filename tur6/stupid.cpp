#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

signed solve() {

	int m;
	if (!(cin >> m)) return 1;;
	int n = 1 << m;
	if (m == 1) {
		cout << 2 << "\n";
		return 0;
	}
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> px(n + 1);
	vector<int> pos(n);
	for (int i = 0; i < n; i++) pos[a[i]] = i;
	for (int i = 0; i < n; i++) px[i + 1] = px[i] ^ a[i];

	set<pair<int, int>> available;
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			available.insert({i, j});
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((px[j + 1] ^ px[i]) == ((1 << m) - 1)) {
				ans++;
				available.erase({i, j});
				continue;
			}
			for (int k = 0; k < n; k++) {
				if (i <= k && k <= j) {
					continue;
				}
				int need = ((1 << m) - 1 - (px[j + 1] ^ px[i])) ^ a[k];
				if (i <= pos[need] && pos[need] <= j) {
					ans ++;
					available.erase({i, j});

					break;
				}
			}

		}
	}

	for (auto i : available) {
		cout << i.first << " " << i.second << " " << (px[i.second + 1] ^ px[i.first]) << "\n";
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