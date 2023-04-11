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
	vector<int> mn(n, n);
	for (int i = 0; i < (1 << (n - 1)); i++) {

		vector<int> res = a;
		for (int j = 0; j < n - 1; j++) {
			if (i >> j & 1) {
				swap(res[j + 1], res[(j + 2) / 2 - 1]);
			}

		}
		if (res < mn) {
			mn = res;
		}
	}

	for (int i = 0; i < n; i++) cout << mn[i] << " "; cout << "\n";
	
	return 1;

}

signed main() {
	int t = 1e9;
	while (t --> 0) {
		if (solve()) break;
	}
}