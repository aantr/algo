#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
ordered_set;

struct segtree {

	std::vector<ordered_set> t;
	int sz = 1;
	segtree (vector<int> &a) {
		while (sz < a.size()) sz <<= 1;
		t.resize(sz * 2);
	}

	int get(int l, int r, int B, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 0;
		if (l <= lx && rx <= r) {
			return t[x].size() - t[x].order_of_key(B + 1);
		}
		int m = lx + rx >> 1;
		return get(l, r, B, x * 2 + 1, lx, m) + get(l, r, B, x * 2 + 2, m, rx);
	}

	void set(int i, int B, int x, int lx, int rx) {
		if (rx - lx == 1) {
			t[x].insert(B);
			return;
		}
		int m = lx + rx >> 1;
		if (i < m) {
			set(i, B, x * 2 + 1, lx, m);
		} else {
			set(i, B, x * 2 + 2, m, rx);
		}
		t[x].insert(B);
	}
};

int solve() {

	int n;
	if (!(cin >> n)) {
		return 1;
	}

	vector<int> a(n);
	segtree st(a);
	for (int i = 0; i < n; i++) {
		int A, B;
		cin >> A >> B;
		cout << st.get(0, A, B, 0, 0, st.sz) << " "; cout.flush();
		st.set(A - 1, B, 0, 0, st.sz);
	}


	return 0;

}

signed main() {
	int t = 1e9;
	while (t--){
		if (solve()) break;
	}
}