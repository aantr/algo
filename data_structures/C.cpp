#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC

vector<int> sizes;

struct segtree {

	std::vector<ll> t, p;
	int sz = 1;
	segtree (vector<int> &a) {
		while (sz < a.size()) sz<<=1;
		t.assign(sz * 2, 0);
		p.assign(sz * 2, 0);
		build(a, 0, 0, sz);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx-lx==1){
			if(lx < a.size())t[x]+=a[lx];
			return;
		}
		int m = lx+rx >> 1;
		build(a, x * 2 + 1, lx, m);
		build(a, x * 2 + 2, m, rx);
		t[x] = t[x * 2 + 1] + t[x * 2 + 2];
	}

	void apply(int x, int lx, int rx, ll v) {
		p[x] += v;
		t[x] += v * (rx - lx);
	}

	void push(int x, int lx, int rx) {
		int m = lx + rx >> 1;
		apply(x * 2 + 1, lx, m, p[x]);
		apply(x * 2 + 2, m, rx, p[x]);
		p[x] = 0;
	}

	ll get(int l, int r) {
		return get(l, r, 0, 0, sz);
	}

	ll get(int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return 0;
		if (l <= lx && rx <= r) return t[x];
		int m = lx + rx >> 1;
		push(x, lx, rx);
		return get(l, r, x * 2 + 1, lx, m) + get(l, r, x * 2 + 2, m, rx);
	}

	void upd(int l, int r, ll v, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return;
		if (l <= lx && rx <= r) {
			apply(x, lx, rx, v);
			return;	
		}
		push(x, lx, rx);
		int m = lx + rx >> 1;
		upd(l, r, v, x * 2 + 1, lx, m);
		upd(l, r, v, x * 2 + 2, m, rx);
		t[x] = t[x * 2 + 1] + t[x * 2 + 2];
	}
};

void solve(){
	
	int n;
	cin >> n;
	vector<array<int, 4>> rect(n);
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		cin >> rect[i][0] >> rect[i][1] >> rect[i][2] >> rect[i][3];
		for (int j : rect[i]) temp.push_back(j);
	}
	sort(temp.begin(), temp.end());
	temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
	for (int i = 0; i < (int)temp.size() - 1; i++) 
		sizes.push_back(temp[i + 1] - temp[i]);
	for (int i = 0; i < n; i++) for (int j = 0; j < 4; j++) 
		rect[i][j] = lower_bound(temp.begin(), temp.end(), rect[i][j]) - temp.begin();
	vector<array<int, 5>> line;
	vector<ll> ans(n);
	for (int i = 0; i < n; i++) {
		line.push_back({rect[i][0], rect[i][1], rect[i][3], -1, i});
		line.push_back({rect[i][2], rect[i][1], rect[i][3], 1, i});
	}

	sort(line.begin(), line.end());
	const int maxn = 4e5 + 5;
	vector<int> st_v(maxn);
	segtree st(st_v);
	for (int i = 0; i < line.size(); i++) {
		auto [x, l, r, k, I] = line[i];
		ans[I] += st.get(l, r) * k;
		if (k == 1) ans[I] -= r - l;
		st.upd(l, r, -k, 0, 0, st.sz);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	ll A = -accumulate(ans.begin(), ans.end(), 0ll) / 2;
	for (int i = 0; i < n; i++) {
		A += (temp[rect[i][2]] - temp[rect[i][0]]) * (temp[rect[i][3]] - temp[rect[i][1]]);
	}
	cout << A << "\n";
}

signed main(){
	int t = 1;
	while (t--){
		solve();
	}
	cerr << "Time: " << TIME << endl;
}