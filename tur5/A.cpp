#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int mod = 1e9 + 7;
const int p2 = 500000004;

void solve() {

	ll n, m, k;
	cin >> n >> m >> k;
	map<int, int> r, c;
	for (int i = 0; i < k; i++) {
		char C;
		ll x, y;
		cin >> C >> x >> y;
		if (C == 'R') {
			if (r.find(x) == r.end()) r[x] = 1;
			r[x] = r[x] * y % mod;
		} else {
			if (c.find(x) == c.end()) c[x] = 1;
			c[x] = c[x] * y % mod;
		}
	}

	int sum = (1 + n % mod * m) % mod * (n % mod * m) % mod * p2 % mod;

	for (auto i : c) {
		sum += ((2 + (n - 1) * m) % mod * n % mod * p2 % mod + n * (i.first - 1) % mod) * 
		(i.second - 1) % mod;
		sum %= mod;
	}

	for (auto i : r) {
		int Sum = ((m * (i.first - 1) % mod + 1) * 2 + (m - 1)) * m % mod * p2;
		for (auto j : c) {
			Sum += (j.second - 1) * (1 + (i.first - 1) * m % mod + (j.first - 1)) % mod;
			Sum %= mod;
		}
		sum += Sum * (i.second - 1) % mod;
		sum %= mod;
	}

	cout << (ll)sum << endl;
}

signed main() {
	int t = 1;
	while (t--) {
		solve();
	}
}
