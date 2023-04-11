#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

void solve() {
	int n, m;
	cin >> n >> m;
	std::vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'C') a[i][j] = 'B';
			if (a[i][j] == 'G') a[i][j] = 'C';
			if (a[i][j] == 'T') a[i][j] = 'D';

		}
	}
	vector<int> used(n);
	vector<int> dist(n);

	for (int i = 0; i < n; i++) {
		int ans = 0;
		for (int j = 0; j < m; j++) {
			ans += min(abs('A' - a[i][j]), 4 - abs('A' - a[i][j]));
		}
		dist[i] = ans;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int mini = 0;
		int mn = 1e9;
		for (int j = 0; j < n; j++) {
			if (!used[j] && dist[j] < mn) {
				mn = dist[j];
				mini = j;
			}
		}
		used[mini] = 1;
		ans += mn;
		for (int j = 0; j < n; j++) {
			int dst = 0;
			for (int k = 0; k < m; k++) {
				dst += min(abs(a[mini][k] - a[j][k]), 4 - abs(a[mini][k] - a[j][k]));
			}
			// dist[i] = ans;

			dist[j] = min(dist[j], dst);
		}
		// cout << mini << " " << mn << endl;
	}
	cout << ans << endl;
}	


signed main () {

	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t --> 0) solve();
	cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << "\n";
}