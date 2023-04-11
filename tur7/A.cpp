#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

void solve () {

	int n, m, k;
	cin >> n >> m >> k;
	std::vector<std::vector<int>> a(n, std::vector<int> (m, 1e9));
	for (int i = 0; i < k; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		x--;
		y--;

		int len = 1;
		int cur = 1;
		array<int, 2> pos = {x, y};
		for (int i = 0; i < 105; i++) {

			int v = 1;
			if (i % 2) v = -1;
			for (int j = 0; j < len; j++) {
				if (0 <= pos[0] && pos[0] < n && 0 <= pos[1] && pos[1] < m) {
					a[pos[0]][pos[1]] = min(a[pos[0]][pos[1]], cur);
				}
				cur++;
				pos[0] += -v;
			}
			for (int j = 0; j < len; j++) {
				if (0 <= pos[0] && pos[0] < n && 0 <= pos[1] && pos[1] < m) {
					a[pos[0]][pos[1]] = min(a[pos[0]][pos[1]], cur);
				}
				cur++;
				if (r == 0) {
					pos[1] += v;
				} else {
					pos[1] += -v;
				}
			}
			len++;
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

}

signed main () {
	int t = 1;
	while (t --> 0) {
		solve();
	}
}