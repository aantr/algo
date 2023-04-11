#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC
const int logn = 20;

struct sparse {
	int n;
	vector<vector<array<int, 2>>> t, tmn;
	sparse (vector<array<int, 2>> a) {
		n = a.size();
		t.resize(logn + 1);
		t[0] = a;
		tmn.resize(logn + 1);
		tmn[0] = a;
		for (int i = 1; i <= logn; i++) {
			t[i].resize(n);
			tmn[i].resize(n);
			for (int j = 0; j + (1 << (i - 1)) < n; j++) {
				t[i][j] = max(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
				tmn[i][j] = min(tmn[i - 1][j], tmn[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	array<int, 2> getmn(int l, int r) {
		int lg = __lg(r - l);
		return min(tmn[lg][l], tmn[lg][r - (1 << lg)]);
	}

	array<int, 2> getmx(int l, int r) {
		int lg = __lg(r - l);
		return max(t[lg][l], t[lg][r - (1 << lg)]);
	}
};

int solve() {

	int n;
	if (!(cin >> n)) return 1;
	vector<array<int, 2>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		a[i][1] = i;
	}

	sparse s(a);
	vector<array<int, 2>> st;
	st.push_back({0, n});
	int ans = 0;
	while (st.size()) {
		int l = st.back()[0];
		int r = st.back()[1];
		st.pop_back();
		if (r - l == 0) continue;
		ans ++;
		int L = s.getmn(l, r)[1];
		int R = s.getmx(L, r)[1] + 1;
		// cout << l << " " << r << " " << L << " " << R << endl;
		st.push_back({l, L});
		st.push_back({R, r});
	}
	cout << ans << "\n";
	return 0;
}

signed main() {
	int t = 1e9;
	// cin >> t;
	while (t--) {
		if (solve()) break;
	}
	cerr << "Time: " << TIME << endl;
}