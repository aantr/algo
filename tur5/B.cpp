#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {

	int n, k;
	cin >> n >> k;
	std::vector<set<int>> a(k);
	for (int i = 0; i < k; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			a[i].insert(x);
		}
	}

	map<string, int> res;

	for (int i = 1; i <= n; i++) {
		string r;
		for (int j = 0; j < k; j++) {
			r += '0' + (a[j].find(i) != a[j].end());
		}
		res[r] += 1;
	}

	if (k > 21 || (k <= 21 && (int)res.size() < (1 << k))) {
		for (int i = 0; i < (1 << 21); i++) {
			string q;
			int x = i;
			for (int j = 0; j < k; j++) {
				q += '0' + (x & 1);
				x >>= 1;
			}
			cerr << "q: " << q << "\n";
			if (res.find(q) == res.end()) {
				cout << q << "\n";
				return;
			}
		}
		return;
	} else {
		int mn = 1e9;
		string ans;
		for (auto i : res) {
			if (i.second < mn) {
				mn = i.second;
				ans = i.first;
			}
		}
		// assert(ans != "");
		cout << ans << endl;
	}

	
}

signed main() {
	int t = 1;
	while (t--) {
		solve();
	}
}