#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

signed solve() {

	int n;
	cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<array<int, 2>> mn(n, array<int, 2>{INT_MAX, 0});
	for (int i = n - 1; i > 0; i--) {
		mn[i] = {a[i], i};
		if ((i + 1) * 2 - 1 < n) mn[i] = min(mn[i], mn[(i + 1) * 2 - 1]);
		if ((i + 1) * 2 < n) mn[i] = min(mn[i], mn[(i + 1) * 2]);
	}

	for (int i = 0; i < n; i++) {
		// cout << mn[i][1] << " ";
	}
	
	vector<int> res = a;

	vector<int> may(n + 1);
	int timer = 0;

	for (int i = 1; i < n; i++) {
		int down = (i + 1) / 2 - 1;
		if (i == n - 1) {
			if (res[down] > res[i]) swap(res[down], res[i]);
			continue;
		}
		if (res[down] == min({res[down], res[i], res[i + 1]})) {
			/*if (res[i] > res[i + 1]) swap(res[i], res[i + 1]);
			if (mn[i] < res[i] && res[i] < mn[i + 1]) {
				swap(res[i], res[i + 1]);
			}*/
		} else if (res[i] == min({res[down], res[i], res[i + 1]})){
			swap(res[i], res[down]);
		} else {
			swap(res[down], res[i + 1]);
			if (res[i] > res[i + 1]) swap(res[i], res[i + 1]);
			if (mn[i][1] > mn[i + 1][1]) {
				swap(res[i], res[i + 1]);
			} else if (0) {
				swap(res[i], res[i + 1]);
			}
		}
		i++;
		cerr << "res: ";
		for (int i = 0; i < n; i++) {
			cerr << res[i] << " ";
		}
		cerr << "\n";
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";


	return 1;

}

signed main() {
	int t = 1e9;
	while (t --> 0) {
		if (solve()) break;
	}
}