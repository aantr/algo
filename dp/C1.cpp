#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int maxn = 2e3 + 5;
const int mod = 1e9 + 9;
const int K = 37;
int stK[maxn];

int binpow(int n, int p) {
	if (p == 0) {
		return 1;
	}
	int ans = binpow(n, p / 2);
	ans = ans * ans % mod;
	if (p & 1) ans = ans * n % mod;
	return ans;
}

void solve() {

	stK[0] = 1;
	for (int i = 1; i < maxn; i++) {
		stK[i] = stK[i - 1] * K % mod;
	}

	int n, m, k;
	cin >> n >> m >> k;
	k--;
	string s;
	cin >> s;
	std::vector<string> v;
	for (int i = 0; i < n; i++) {
		string cur;
		for (int j = i; j < n; j++) {
			cur = cur + s[j];
			v.push_back(cur);
		}
	}

	vector<int> H(n + 1);
	H[0] = 0;
	for (int i = 1; i <= n; i++) {
		H[i] = (H[i - 1] + stK[i] * (s[i - 1] - 'a' + 1) ) % mod;
	}

	function<int(int, int)> Hash = [&](int l, int r) {
		return (H[r] - H[l] + mod) * binpow(stK[l], mod - 2);
	};

	sort(v.begin(), v.end());
	int l = 0, r = v.size();
	while (r - l > 1) {
		int mid = l + r >> 1;
		string cur = v[mid];
		vector<int> h(cur.size() + 1);
		h[0] = 0;
		for (int i = 0; i < (int)h.size() - 1; i++) {
			h[i + 1] = (h[i] + stK[i + 1] * (cur[i] - 'a' + 1)) % mod;
		}

		// count of razb such that every string is not less than our
		vector<vector<int>> dp(n + 1, vector<int> (m + 1));
		dp[n][0] = 1;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 1; j <= m; j++) {

				int L = 0, R = min(n - i, (int)cur.size()) + 1;
				while (R - L > 1) {
					int M = L + R >> 1;
					if (Hash(i, i + M) == h[M]) {
						L = M;
					} else {
						R = M;
					}
				}
				int len = L;
				if (len == cur.size()) {
					for (int q = i + len; q <= n; q++) {
						dp[i][j] += dp[q][j - 1];
					}
				} else if (len + i < n && s[i + len] >= cur[len]) {
					for (int q = i + len + 1; q <= n; q++) {
						dp[i][j] += dp[q][j - 1];
					}
				}
				
			}
		}

		if (dp[0][m] > k) {
			l = mid;
		} else {
			r = mid;
		}

	}
	// cout << l << endl;
	cout << v[l] << "\n";

}

signed main () {
	int t = 1;
	while (t--) {
		solve();
	}
}