#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ul;
#define int ll	
#define TIME (double) clock() / CLOCKS_PER_SEC

ostream& operator << (ostream &s, pair<int, int> a) {
	s << a.first << " " << a.second;
	return s;
} 

struct segtree {

	int K, mod;

	vector<int> t, p;
	int sz = 1;
	vector<int> k;
	vector<int> pref_K;
	segtree (vector<int> &a, int K, int mod): K(K), mod(mod) {
		while (sz < a.size()) sz <<= 1;
		t.assign(sz * 2, 0);
		p.assign(sz * 2, -1);
		pref_K.assign(sz, 0);
		k.assign(sz, 0);
		k[0] = 1;
		for (int i = 1; i < sz; i++) k[i] = k[i - 1] * K % mod;
		pref_K[1] = 1;
		for (int i = 2; i < sz; i++) {
			pref_K[i] = (pref_K[i - 1] + k[i - 1]) % mod;
		}
		build(a, 0, 0, sz);
	}

	pair<int, int> compile(pair<int, int> a, pair<int, int> b){
		return {(a.first + k[a.second] * b.first) % mod, a.second + b.second};
	}

	void apply(int x, int lx, int rx, int v){
		p[x] = v;
		t[x] = v * (pref_K[rx - lx]) % mod;
	}

	void push(int x, int lx, int rx) {
		if (p[x] == -1 || rx-lx==1) return;
		int m = lx + rx >> 1;
		apply(x * 2 + 1, lx, m, p[x]);
		apply(x * 2 + 2, m, rx, p[x]);
		p[x] = -1;
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) t[x] = a[lx] % K;
			return;
		}
		int m = lx + rx >> 1;
		build(a, x * 2 + 1, lx, m);
		build(a, x * 2 + 2, m, rx);
		t[x] = compile({t[x * 2 + 1], rx - lx >> 1}, {t[x * 2 + 2], rx - lx >> 1}).first;
	}

	pair<int, int> get(int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) {
			return {0, 0};
		}
		if (l <= lx && rx <= r) {
			return {t[x], rx - lx};
		}
		push(x, lx, rx);
		int m = lx + rx >> 1;
		auto v1 = get(l, r, x * 2 + 1, lx, m), v2 = get(l, r, x * 2 + 2, m, rx);
		return compile(v1, v2);

	}

	void upd(int l, int r, int v, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return;
		if (l <= lx && rx <= r) {
			apply(x, lx, rx, v);
			return;
		}
		int m = lx + rx >> 1;
		push(x, lx, rx);
		upd(l, r, v, x * 2 + 1, lx, m);
		upd(l, r, v, x * 2 + 2, m, rx);
		t[x] = compile({t[x * 2 + 1], rx - lx >> 1}, {t[x * 2 + 2], rx - lx >> 1}).first;
	}


};



void solve(){	
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	segtree st(a, 100049, 1e9+7);
	int q;
	cin >> q;
	while (q--) {
		int t, l, r, k;
		cin >> t >> l >> r >> k;
		if (t == 0) {
			l--;
			st.upd(l, r, k, 0,0,st.sz);
		} else {
			l--;
			r--;
			auto v1 = st.get(l, l + k, 0, 0, st.sz);
			auto v2 = st.get(r, r + k, 0, 0, st.sz);
			cout << (v1 == v2 ? '+' : '-');
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