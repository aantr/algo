#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC

struct segtree {

	vector<array<int, 3>> t;
	int sz = 1;

	segtree (vector<int> &a) {
		while (sz < a.size()) sz <<= 1;
		t.assign(sz * 2, {});
		build(a, 0, 0, sz);
	}

	array<int, 3> compile(array<int, 3> a, array<int, 3> b, int lx, int rx) {
		array<int, 3> res;
		res[1] = a[1];
		res[2] = b[2];
		if (a[1] == (lx+rx>>1)) res[1] += b[1];
		if (b[2] == (lx+rx>>1)) res[2] += a[2];
		res[0] = max(a[2] + b[1], max(max(res[1], res[2]), max(a[0], b[0])));
		return res;
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
			t[x][0] = t[x][1] = t[x][2] = a[lx] == 0;
			}
			return;
		}
		int m = lx + rx >> 1;
		build(a, x * 2 + 1, lx, m);
		build(a, x * 2 + 2, m, rx);
		t[x] = compile(t[x * 2 + 1], t[x * 2 + 2], rx, lx);
	}

	void upd(int i, int x) {
		upd(i, x, 0, 0, sz);
	}

	void upd(int i, int v, int x, int lx, int rx){
		if (rx - lx == 1){
			t[x][0] = t[x][1] = t[x][2] = v == 0;
			return;
		}
		int m = lx + rx >> 1;
		if (i < m) upd(i, v, x * 2 + 1, lx, m);
		else upd(i, v, x * 2 + 2, m, rx);
		t[x] = compile(t[x * 2 + 1], t[x * 2 + 2], rx, lx);
	}

	array<int, 3> get(int l, int r) {
		return get(l, r, 0, 0, sz);
	}

	array<int, 3> get(int l, int r, int x, int lx, int rx){
		if (lx >= r || rx <= l) return {};
		if (l <= lx && rx <= r) {
			return t[x];
		}
		int m = lx + rx >> 1;
		return compile(get(l, r, x * 2 + 1, lx, m), 
			get(l, r, x * 2 + 2, m, rx), lx, rx);
	}

};

void solve(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin>>a[i];
	segtree st(a);
	int q;
	cin>>q;
	for (int i = 0; i < q; i++) {
		string t;
		int l, r;
		cin>>t>>l>>r;
		l--;
		if (t == "QUERY") {
			cout << st.get(l, r)[0] << "\n";
		} else {
			st.upd(l, r);
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