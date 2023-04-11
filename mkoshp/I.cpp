#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct segtree{

	vector<int> t;
	int sz = 1;
	segtree(vector<int> a){
		while (sz < a.size()) sz <<=1;
		t.assign(sz * 2, inf);
		build(a, 0, 0, sz);
	}
	void build(vector<int> &a, int x, int lx, int rx){
		if (rx == lx){
			if (lx < a.size()) t[x] = a[lx];
			return;
		}
		int m = lx+rx>>1;
		build(a, x * 2 + 1, lx, m);
		build(a, x * 2 + 2, m, rx);
		t[x] = min(t[x * 2 + 1], t[x * 2 + 2]);
	}

	void set(int i, int v){
		return set(i, v, 0, 0, sz);
	}

	void set(int i, int v, int x , int lx, int rx){
		if (lx + 1 == rx){
			t[x] = v;
			return;
		}
		int m = lx + rx >> 1;
		if (i < m) set(i, v, x * 2 + 1, lx, m);
		else set(i, v, x * 2 + 2, m, rx);
		t[x] = min(t[x * 2 + 1], t[x * 2 + 2]);
	}

	int get(int i){
		return get(i, 0, 0, sz);
	}

	int get(int i, int x, int lx, int rx){
		if (lx + 1 == rx){
			return t[x];
		}
		int m = lx + rx >> 1;
		if (i < m) return get(i, x * 2 + 1, lx, m);
		else return get(i, x * 2 + 2, m, rx);
	}

};

void solve(){
	
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for (int i = 0;i<n;i++) cin>>a[i];
	for (int i = 0;i<n;i++) cin>>b[i];
	vector<vector<int>> available_idx(n);
	for (int i = 0;i < n;i++){
		available_idx[i + b[i]].push_back(i);
	}
	vector<int> dp(n, inf);
	segtree st(dp);
	for (int i = 0;i < n;i++){
		if (i - a[i] < 0) st.set(i, 1);
		else st.set(i, st.get(i - a[i], i) + 1);
		for (int j : available_idx[i]){

		}
	}


}

signed main() {
	int t = 1;
	// cin >> t;
	while (t--) solve();
}