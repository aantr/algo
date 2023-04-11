#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define int ll

const int mod = 1e9 + 9;

void solve() {

	int n, m;
	cin >> n >> m;
	std::vector<std::vector<char>> a(n, std::vector<char> (m));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			cnt += a[i][j] == '*';
		}
	}
	cnt /= 2;
	vector<vector<int>> ans(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt -= a[i][j] == '*';
			ans[i][j] = 1;
			if (cnt == 0) {
				break;
			}
		}
		if (cnt == 0) {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] + 1 << "";
		}
		cout << "\n";
	}
}	

signed main() {
	int t = 1;
	while (t--) {
		solve();
	}
}