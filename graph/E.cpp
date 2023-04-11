#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC

std::vector<std::vector<int>> gr[2];
vector<int> used;
vector<vector<int>> is[2];

void dfs (int v, int col) {
	// cout << "v: " << v << endl;
	used[v] = 1;
	for (auto i : gr[col][v]) {
		if (!used[i]) {
			dfs(i, col);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	gr[0].resize(n);
	gr[1].resize(n);
	for (int i = 0; i < n - 1; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n - 1 - i; j++) {
			if (s[j] == 'R') {
				gr[0][i].push_back(i + j + 1);
			} else {
				gr[1][i].push_back(j + i + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, 0);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cerr << is[i][j] << " ";
			if (is[i][j] == 3) {
				cout << "Yes\n";
				return;
			}
		}
		cerr << "\n";
	}
	cout << "No\n";
}

signed main () {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	while (t--) solve();
	cerr << "Time: " << TIME << "\n";
}