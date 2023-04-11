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
	// заметим, что можно понять будет ли учитываться текущий товар в сумме, 
	// зная только скольо всего товаров будет выбрано для перекладывания и сколько перекладываний было до этого товара
	int mn = 1e9;
	for (int M = 0; M <= min(m, n); M++) {

		vector<vector<int>> dp(n + 1, vector<int> (M + 1, 1e9));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= min(i, M); j++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + ((i - j) % k == 0 ? 0 : a[i - 1]));
				if (j > 0) {	
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + ((j + (n - M)) % k == 0 ? 0 : a[i - 1]));
				}
			}
		}
		// cerr << M << " " << dp[n][M] << "\n";
		mn = min(mn, dp[n][M]);
	}
	cout << mn << "\n";

}

signed main () {
	int t = 1;
	while (t --> 0) {
		solve();
	}
}