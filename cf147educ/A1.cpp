#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()

const int maxn = 1e6;
vector<int> gr[maxn];
int used[maxn];

int dfs(int v) {
	used[v] = 1;
	int ans = 1;
	for (int i : gr[v]) {
		if (!used[i]) ans += dfs(i);
	}
	return ans;
}

void solve() {

	int n, l, r;
	cin >> n >> l >> r;
	std::vector<int> v(n + 1);
	v[0] = 0;
	set<int> m;
	vector<int> cnt(n + 1);
	for (int j = 0; j <= n; j++) m.insert(j);
	for (int i = 1; i <= n; i++) { // todo : optimize

		//  i - l        +
		//  i - r - 1    - 

		if (i - l >= 0) {
			for (int j = 0; j <= i - l; j++) {
				int idx = v[j] ^ v[i - l - j];
				cnt[idx]++;
				// cout << idx << " ";
				if (cnt[idx] == 1) {
					m.erase(idx);
				}
			}
			// cout << "\n";
		}
		if (i - r - 1 >= 0) {
			for (int j = 0; j <= i - r - 1; j++) {
				int idx = v[j] ^ v[i - r - j - 1];
				cnt[idx]--;
				if (cnt[idx] == 0) {
					m.insert(idx);
				}
			}
		}

		int M = *m.lower_bound(0);
		v[i] = M;
		// cout << v[i] << " ";
	}
	// cout << "\n";


	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			int len = dfs(i);
			set<int> m;
			for (int j = 0; j <= len; j++) m.insert(j);
			for (int j1 = 0; j1 < len; j1++) {
				if (len - j1 >= l && len - j1 <= r) {
					m.erase(v[j1]);
				}
			}
			cout << len << " " << *m.lower_bound(0) << "  ";
			x ^= *m.lower_bound(0);

		}
	}

	cout << (x ? "Alice" : "Bob") << "\n";

}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	// precalc();
	int t = 1;
	// cin >> t;
	while (t --> 0) solve();
}