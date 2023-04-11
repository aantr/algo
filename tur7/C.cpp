// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!
// СЛАБЫЕ ТЕСТЫ,  ЭТО РЕШЕНИЕ ДОЛЖНО БЫТЬ WA  !!!!!!!



























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

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll mn = 1e18;
	ordered_set t1, t2;
	node* T1 = nullptr, *T2 = nullptr;
	for (int i = 0; i < n; i++) {
		t2.insert({n - i - a[i], i});

		auto [l, r] = split(T2, n - i - a[i]);
		T2 = merge(merge(l, new node(n - i - a[i])), r);
	}

	function<int()> get_m = [&]() { // O(log n)
		std::vector<int> res;
		int v = 0, v1 = 0;
		if (t1.size() + 1 > t2.size()) {
			v1 += t1.size() + 1 - t2.size();
		} else {
			v -= t1.size() + 1 - t2.size();
		}
		for (int i = -1 -1+ t1.size() % 2; i <= 1; i++) {
			if (i + t1.size() / 2 >= 0 && i + t1.size() / 2 < t1.size()) {
				res.push_back((*t1.find_by_order(t1.size() / 2 + i)).first + v);
			}
		}
		for (int i = -1 - 1 + t2.size() % 2; i <= 1; i++) {
			if (i + t2.size() / 2 >= 0 && i + t2.size() / 2 < t2.size()) {
				res.push_back((*t2.find_by_order(t2.size() / 2 + i)).first + v1);
			}
		}
		
		sort(res.begin(), res.end());
		// cout << "res: "; for (int i : res) cout << i << " "; cout << "\n";
		// cout << "t1: "; for (auto i : t1) cout << i.first + v << " "; cout << "\n";
		// cout << "t2: "; for (auto i : t2) cout << i.first + v1 << " "; cout << "\n";
		return max((int)0, -res[res.size() / 2]);
	};

	for (int i = 0; i < n; i++) {
		ll sum = 0, SUM = 0;
		int M = -get_m();
		int v = 0, v1 = 0;
		if (t1.size() + 1 > t2.size()) {
			v1 += t1.size() + 1 - t2.size();
		} else {
			v -= t1.size() + 1 - t2.size();
		}


		// for (auto i : t1) {
		// 	if (i.first + v >= M) {
		// 		sum += i.first + v - M;
		// 	} else  {
		// 		sum -= i.first + v - M;
		// 	}
		// }

		auto [L, R] = split(T1, M - v);
		SUM += -getsum(L) - (v - M) * getsz(L) + getsum(R) + (v - M) * getsz(R);
		T1 = merge(L, R);
		// cout << sum << " " << SUM << endl;

		// for (auto i : t2) {
		// 	if (i.first + v1 >= M) {
		// 		sum += i.first + v1 - M;
		// 	} else  {
		// 		sum -= i.first + v1 - M;
		// 	}
		// 	cout << i.first << " ";
		// }
		// cout << "\n";


		auto [L1, R1] = split(T2, M - v1);
		SUM += -getsum(L1) - (v1 - M) * getsz(L1) + getsum(R1) + (v1 - M) * getsz(R1);
		T2 = merge(L1, R1);
		mn = min(mn, SUM);

		t2.erase({n - i - a[i], i});
		t1.insert({i + 1 - a[i], i});


		auto [l1, r1] = split(T2, n - i - a[i]);
		auto [l2, r2] = split_sz(r1, 1);
		T2 = merge(l1, r2);
		auto [l, r] = split(T1, i + 1 - a[i]);
		T1 = merge(merge(l, new node(i + 1 - a[i])), r);

	}

	cout << mn << "\n";

}

signed main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	while (t --> 0) {
		solve();
	}
}