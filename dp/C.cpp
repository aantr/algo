#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int inf = LLONG_MAX;

void solve() {

	int n, m, g;
	cin >> n >> m >> g;
	std::vector<std::vector<array<int, 4>>> gr(n);
	vector<array<int, 4>> edges; 
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		if (d != -1) d--;
		edges.push_back({a, b, c, d});
		gr[a].push_back({b, i, c, d});
		// gr[b].push_back({a, i, c, d});
	}

	set<array<int, 5>> queue;
	queue.insert({0, 0, -1, 0, -1});
	vector<int> ans(n, inf), used_edge(m), used(n);

	while (queue.size()) {
		auto [dist, vert, d, c, idx_edge] = *queue.begin();
		queue.erase(queue.begin());
		// cout << vert << endl;
		if (~idx_edge && !used_edge[idx_edge]) {
			used_edge[idx_edge] = 1;
		}
		if (d != -1 && edges[d][0] == vert && used_edge[d] == 0) {
			queue.insert({dist + max(0ll, c - 1), edges[d][1], edges[d][3], max(0ll, c - 1), d});
		}
		ans[vert] = min(ans[vert], dist);

		// cout << vert + 1 << " " << dist + c << "\n";
		if (!used[vert]) {
			for (auto [v, idx, cost, cur_d] : gr[vert]) {
				// cout << "insert : " << v << " " << cost << " " << d << " " << idx << "\n";
				if (!used_edge[idx]) {
					queue.insert({dist + cost, v, cur_d, cost, idx});
				}
			}
			used[vert] = 1;
		}
		
	}

	for (int i = 0; i < n; i++) {
		cout << (ans[i] == inf ? -1 : ans[i]) << " ";
	}
	cout << "\n";

}

signed main () {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
	cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << "\n";
}