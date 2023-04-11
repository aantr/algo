#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

const int maxn = 2e5 + 5;
std::vector<array<int, 2>> gr[maxn];
int dp[maxn][3];
int used[maxn];
int col[maxn];

void dfs_col(int v, int p = -1) {
	used[v] = 1;
	for (auto i : gr[v]) {
		if (i[0] != p) {
			col[i[0]] = 1 - col[v];
			dfs(i[0], v);
		}
	}
}

void dfs(int v){
	used[v] = 1;
	int cnt0 = 0, cnt1 = 0;
	for (auto i : gr[v]) {
		if (!used[i[0]]) {
			dfs(i[0]);
			if (dp[i[0]][1])
		}
	}
}

void solve() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].push_back({b, 0});
		gr[b].push_back({a, 1});
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs_col(i);
		}
	}
	fill(used, used + maxn, 0);
	for (int i = 0; i < n; i++) {
		for (auto &j : gr[i]) {
			j[1] = (col[i] + j[1]) % 2;
			cout << i << " " << j[0] << " " << j[1] << "\n";
		}
	}

	int ok = 1;
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
		ok &= dp[i][0] == 1;

	}

	cout << (ok ? "Yes": "No") << "\n";
	for (auto i : ans) cout << i.first << " " << i.second << "\n";
	
}

signed main () {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}