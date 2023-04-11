#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int mod = 1e9 + 7;
std::vector<array<int, 4>> Q;

int sq(int x) {
	return x * x;
}

void solve () {

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Q.push_back({a, b, c, d});
	}
	#ifdef ON_PC
	if (1) {
	#else
	if (n <= 1000) {
	#endif
		vector<vector<int>> a(2 * n + 2, vector<int> (2 * n + 2)), p;
		array<int, 2> pos = {};
		int cur = 1;
		int len = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < len; j++) {
				a[pos[0] + n][pos[1] + n] = cur++;
				pos[1]++;
			}
			for (int j = 0; j < len; j++) {
				a[pos[0] + n][pos[1] + n] = cur++;
				pos[0]--;
			}

			len++;
			for (int j = 0; j < len; j++) {
				a[pos[0] + n][pos[1] + n] = cur++;
				pos[1]--;
			}
			for (int j = 0; j < len; j++) {
				a[pos[0] + n][pos[1] + n] = cur++;
				pos[0]++;
			}
			len++;
		}
		for (int j = 0; j < len; j++) {
			a[2 * n][j] = cur++;
		}
		p.assign(n * 2 + 2, vector<int> (n * 2 + 2));
		for (int i = 0; i < n * 2 + 1; i++) {
			for (int j = 0; j < n * 2 + 1; j++) {
				cout << a[i][j] << "\t\t";
				p[i + 1][j + 1] = (a[i][j] + p[i + 1][j] + p[i][j + 1] - p[i][j] + mod) % mod;
			}
			cout << "\n";
		}
		for (int i = 0; i < q; i++) {
			auto [c1, r2, c2, r1] = Q[i];
			r1 = n - r1;
			r2 = n - r2;
			c1 += n;
			c2 += n;
			r2++;
			c2++;
			cout << (p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1] + mod + mod) % mod << "\n";
		}
		return;
	}

	for (int i = 0; i < q; i++) {
		auto [c1, r2, c2, r1] = Q[i];
		r1 = n - r1;
		r2 = n - r2;
		c1 += n;
		c2 += n;
		r2++;
		c2++;
		if (r2 == r1 + 1 && c2 == c1 + 1) {
			int d = max(abs(r1 - n), abs(c1 - n));
			if (d == 0) cout << 1 << "\n";
			else {
				if (r1 == n + d) {
					cout << (sq(2 * d + 1) - (n + d - c1)) % mod << "\n";
				} else if (c1 == n - d) {
					cout << (sq(2 * d + 1) - 2 * d - (n + d - r1)) % mod << "\n";
				} else if (r1 == n - d) {
					cout << (sq(2 * d + 1) - 4 * d - (c1 - (n - d))) % mod << "\n";
				} else {
					cout << (sq(2 * d + 1) - 6 * d - (r1 - (n - d))) % mod << "\n";
				}
			}
		} else if (c1 == n + 1 && r2 == n) {
			
		}
	}

}

signed main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	while (t --> 0) {
		solve();
	}
}