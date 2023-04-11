#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int ll

const int maxn = 1e5 + 100;

int a[maxn];

struct node {
	node * l = nullptr, *r = nullptr;
	ll sum = 0, sz = 1, v;
	int pr;

	node (int v) : v(v) {
		pr = rand();
		sum = v;
	}
};

int getsz(node * v) {
	if (!v) return 0;
	return v->sz;
}

int getsum(node * v) {
	if (!v) return 0;
	return v->sum;
}

void update(node * v){
	if (!v) return;
	v->sz = getsz(v->l) + 1 + getsz(v->r);
	v->sum = getsum(v->l) + v->v + getsum(v->r);
}

node * merge(node * a, node *b) {
	if (!a) return b;
	if (!b) return a;
	if (a->pr > b->pr) {
		a->r = merge(a->r, b);
		update(a);
		return a;
	} else {
		b->l = merge(a, b->l);
		update(b);
		return b;
	}
}

pair<node*, node*> split(node * v, int k) {
	if (!v) return {nullptr, nullptr};
	if (v->v >= k) {
		auto [l, r] = split(v -> l, k);
		v->l = r;
		update(v);
		return {l, v};
	} else  {
		auto [l, r] = split(v -> r, k);
		v -> r = l;
		update(v);
		return {v, r};
	}
}

pair<node*, node*> split_sz(node * v, int k) {
	if (!v) return {nullptr, nullptr};
	if (getsz(v->l) + 1 > k) {
		auto [l, r] = split_sz(v -> l, k);
		v->l = r;
		update(v);
		return {l, v};
	} else  {
		auto [l, r] = split_sz(v -> r, k - (getsz(v->l) + 1));
		v -> r = l;
		update(v);
		return {v, r};
	}
}

void print(node * v) {
	if (!v) return;
	print(v->l);
	cout << v->v << " ";
	print(v->r);
}

void solve () {

	function<int(ordered_set&, ordered_set&)> get_m = [&](ordered_set &t1, ordered_set &t2) { // O(log n)
		std::vector<int> res;
		int v = 0, v1 = 0;

		for (int i = -4 -1+ t1.size() % 2; i <= 4; i++) {
			if (i + t1.size() / 2 >= 0 && i + t1.size() / 2 < t1.size()) {
				res.push_back((*t1.find_by_order(t1.size() / 2 + i)).first + v);
			}
		}
		for (int i = -4 - 1 + t2.size() % 2; i <= 4; i++) {
			if (i + t2.size() / 2 >=	 0 && i + t2.size() / 2 < t2.size()) {
				res.push_back((*t2.find_by_order(t2.size() / 2 + i)).first + v1);
			}
		}
		
		sort(res.begin(), res.end());
		cout << "res: "; for (int i : res) cout << i << " "; cout << "\n";
		cout << "t1: "; for (auto i : t1) cout << i.first + v << " "; cout << "\n";
		cout << "t2: "; for (auto i : t2) cout << i.first + v1 << " "; cout << "\n";
		return max((int)0, -res[res.size() / 2]);
	};

	for (int _ = 0; _ < 100; _++) {
		ordered_set t1, t2;

		const int K = 40;
		vector<int> res;
		for (int i = 0; i < K; i++) {
			int v = -(rand() % 100);
			t1.insert({v, i}), res.push_back(v);
		}
		for (int i = 0; i < K; i++) {
			int v = -(rand() % 100);
			t2.insert({v, i + K}), res.push_back(v);
		}
		sort(res.begin(), res.end());
		for (int i : res) cout << i << " "; cout << "\n";

		int r = -get_m(t1, t2);
		cout << res[res.size() / 2] << " " << r << "\n";
		if (r != res[res.size() / 2] && r != res[res.size() / 2 - 1]) {
			cout << "err\n";
			return;
		} else {
			cout << "ok\n";
		}
	}

	

}

signed main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	while (t --> 0) {
		solve();
	}
}