#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

const ll inf = LLONG_MAX / 2;

ll st10[15];

ll get(int x) {
	if (x % 2 == 0) return st10[x / 2];
	return 5 * st10[x / 2];
}

int chmax(ll &a, ll b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

void solve() {

	string s;
	cin >> s;
	int n = s.size();
	std::vector<std::vector<ll>> dp(n + 1, std::vector<ll> (26, -inf));
	vector<vector<pair<int, int>>> parent(n + 1, std::vector<pair<int, int>> (26, {-1, -1}));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			int k;
			if (s[n - i] != '?') {
				k = s[n - i] - 'A';
				if (k < j) {
					if (chmax(dp[i][j], dp[i - 1][j] - get(k))) {
						parent[i][j] = {j, k};
					}
				} else {
					if (chmax(dp[i][k], dp[i - 1][j] + get(k))) {
						parent[i][k] = {j, k};
					}
				}
			} else {
				for (int q = 0; q < 26; q++) {
					k = q;
					if (k < j) {
						if (chmax(dp[i][j], dp[i - 1][j] - get(k))) {
							parent[i][j] = {j, k};
						}
					} else {
						if (chmax(dp[i][k], dp[i - 1][j] + get(k))) {
							parent[i][k] = {j, k};
						}
					}
				}
			}

		}
	}

	ll ans = -inf;
	int k = 0;
	for (int i = 0; i < 26; i++) {
		if (dp[n][i] > ans) {
			ans = dp[n][i];
			k = i;
		}
	}
	cout << ans << "\n";
	string A;
	int N = n;
	while (N) {
		int ok = 0;
		pair<int, int> cur = parent[N][k];
		A += 'A' + cur.second;
		k = cur.first;
		N--;
	}
	// reverse(A.begin(), A.end());
	cout << A << "\n";
}

signed main () {

	st10[0] = 1;
	for (int i = 1; i < 15; i++) {
		st10[i] = st10[i - 1] * 10;
	}

	int t = 1;
	cin >> t;
	while (t--) solve();
}