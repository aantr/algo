#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

const int K = 500;

void solve() {

	int n, q;
	cin >> n >> q;
	std::vector<array<int, 2>> a(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	vector<array<int, 3>> Q;

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		Q.push_back({l, r, i});
	}

	sort(Q.begin(), Q.end(), [&] (array<int, 3> &a, array<int, 3> &b) {
		return a[0] / K < b[0] / K || a[0] / K == b[0] / K && a[1] < b[1];
	});

	vector<int> ans(q);

	int L = 0, R = 0;
	deque<int> st;
	for (int i = 0; i < q; i++) {	
		auto [l, r, _] = Q[i];
		if (i && Q[i - 1][1] > r) {
			L = 0;
			R = 0;
			st.clear();
		}
		L = r;
		R = r;
		st.clear();
		while (R < r) {
			int j = R;
			R++;
			st.push_back(j);
			if (st.back() > 0 && (st.size() > 1 && a[st.back()][0] - a[st.back()][1] >= a[st[(int)st.size() - 2]][0] || 
										st.size() == 1 && a[st.back()][0] - a[st.back()][1] >= a[max(0, l - 1)][0])) {
				st.pop_back();
			}
			while (st.size() > 0 && st.back() < n - 1 && a[st.back()][0] + a[st.back()][1] <= a[min(n - 1, j + 1)][0]) {
				st.pop_back();
			}
		}
		while (L > l) {
			L--;
			int j = L;
			st.push_front(j);
			if (st.front() < n - 1 && (st.size() > 1 && a[st.front()][0] + a[st.front()][1] <= a[st[1]][0] || 
										st.size() == 1 && a[st.front()][0] + a[st.front()][1] <= a[min(n - 1, r)][0])) {
				st.pop_front();
			}
			while (st.size() > 0 && st.front() > 0 && a[st.front()][0] - a[st.front()][1] >= a[max(0, j - 1)][0]) {
				st.pop_front();
			}
		}
		while (L < l) {
			int j = L;
			L++;
			if (st.front() == j) {
				st.pop_front();
			}
		}
		ans[Q[i][2]] = r - l - (int)st.size();
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
}

signed main () {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}