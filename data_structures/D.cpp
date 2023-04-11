#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC

struct segtree {

	vector<int> t;
	int sz = 1;

	segtree (vector<int> &a) {
		while (sz < a.size()) sz <<= 1;
		t.resize(sz * 2);
		build(a, 0, 0, sz);
	}

	void build(vector<int> &a, int x, int lx, int rx){
		if (rx-lx==1){
			if (lx < a.size()) t[x]=a[lx];
			return;
		}
		int m = lx + rx >> 1;
		build(a, x * 2 + 1, lx, m);
		build(a, x * 2 + 2, m, rx);
		t[x] = t[x * 2 + 1] + t[x * 2 + 2];
	}

	int first(int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return -1;
		int m = lx + rx >> 1;
		if (l <= lx && rx <= r) {
			if (rx-lx == 1) {
				if (t[x] == 0) return -1;
				return lx;
			}
			if (t[x * 2 + 1] > 0) {
				return first(l, r, x * 2 + 1, lx, m);
			}
			return first(l, r, x * 2 + 2, m, rx);
		}

		int ans = first(l, r, x * 2 + 1, lx, m);
		if (ans != -1) return ans;
		return first(l, r, x * 2 + 2, m, rx);

	}

	void upd(int i, int v, int x, int lx, int rx){
		if (rx - lx == 1){
			t[x] += v;
			return;
		}
		int m = lx + rx >> 1;
		if (i < m) upd(i, v, x * 2 + 1, lx, m);
		else upd(i, v, x * 2 + 2, m, rx);
		t[x] = t[x * 2 + 1] + t[x * 2 + 2];
	}
		
};

void solve(){
	
	int n;
	cin >> n;
	vector<int> a(2e5 + 5, 1);
	segtree st(a);
	for (int i = 0; i < n; i++) {
		int x;
		cin>>x;
		if (x > 0) {
			int f = st.first(x, a.size(), 0, 0, st.sz);
			cout << f << "\n";
			st.upd(f, -1, 0, 0, st.sz);
		} else {
			st.upd(-x, 1, 0, 0, st.sz);
		}
	}

}

signed main(){
	int t = 1;
	while (t--){
		solve();
	}
	cerr << "Time: " << TIME << endl;
}