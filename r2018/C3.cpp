#include <bits/stdc++.h>
using namespace std;
#define TIME (double) clock() / CLOCKS_PER_SEC

mt19937 rnd(1234);

struct node {
	node * l = nullptr, *r = nullptr;
	int v, pr, sz=1, mx;
	node (int v) : v(v), mx(v){
		pr = rnd();
	}
};

int getsz(node * v){
	if (!v) return 0;
	return v->sz;
}

int getmx(node * v){
	if (!v) return -1e9;
	return v->mx;
}

void upd(node * v){
	if (!v) return;
	v->sz = 1 + getsz(v->l) + getsz(v->r);
	v->mx = max(v->v, max(getmx(v->l), getmx(v->r)));
}

pair<node*, node*> split(node *root, int k){
	if (!root){
		return {nullptr, nullptr};
	}
	if (getsz(root->l) + 1 <= k) {
		auto res = split(root->r, k - (getsz(root->l) + 1));
		root->r = res.first;
		upd(root);
		return {root, res.second};
	} else {
		auto res = split(root -> l, k);
		root -> l = res.second;
		upd(root);
		return {res.first, root};
	}
}

pair<node*, node*> splitv(node *root, int v){
	if (!root){
		return {nullptr, nullptr};
	}
	if (root->v < v) {
		auto res = splitv(root->r, v);
		root->r = res.first;
		upd(root);
		return {root, res.second};
	} else {
		auto res = splitv(root -> l, v);
		root -> l = res.second;
		upd(root);
		return {res.first, root};
	}
}

node * merge(node * l, node * r){
	if (!l) return r;
	if (!r) return l;
	if (l->pr < r->pr){
		r->l = merge(l, r->l);
		upd(r);
		return r;
	} else {
		l -> r = merge(l -> r, r);
		upd(l);
		return l;
	}
}

void get(node * v){
	if (!v) return;
	get(v->l);
	cout << v->v << " ";
	get(v->r);
}

int lb(node *root, int v) {
	if (!root) return 0;
	if (root->l && root->l->mx >= v) return lb(root->l, v);
	if (root->v >= v) return getsz(root->l);
	return lb(root->r, v) + getsz(root->l) + 1;
}

void solve(){
	int n, p;
	cin >> n >> p;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (p == 2) {
		vector<int> mx (n, -1e9);

		for (int mask = 1; mask < 3; mask ++) {
			vector<int> left(n, n), right(n, n);
			if (mask & 1) left[0] = 0;
			if (mask >> 1 & 1) right[n - 1] = 0;
			for (int i = 0; i < n; i++) {
				if (i) left[i] = min(left[i], left[i - 1] + 1);
			}
			for (int i = n - 1; i >= 0; i--) {
				if (i < n - 1) right[i] = min(right[i], right[i + 1] + 1);
			}

			vector<array<int, 2>> chel(n);
			for (int i = 0;i < n; i++) {
				chel[i][1] = i;
				chel[i][0] = a[i] + min(left[i], right[i]);
			}
			sort(chel.begin(), chel.end());
			vector<int> place(n);
			for (int i = 0;i < n; i++) {
				place[i] = i;
				if (i && chel[i][0] == chel[i - 1][0]) {
					place[i] = place[i - 1];
				}
	 			mx [chel[i][1]] = max(mx[chel[i][1]], place[i]);
			}
		}

		for (int j = 0; j < n; j++){
			vector<int> left(n, n), right(n, n);
			int dst = min(j, n-1-j);
			for (int i = 0; i < n; i++) {
				if (abs(i-j) >= dst) left[i]=0,right[i]=0;
			}
			for (int i = 0; i < n; i++) {
				if (i) left[i] = min(left[i], left[i - 1] + 1);
			}
			for (int i = n - 1; i >= 0; i--) {
				if (i < n - 1) right[i] = min(right[i], right[i + 1] + 1);
			}

			vector<array<int, 2>> chel(n);
			for (int i = 0;i < n; i++) {
				chel[i][1] = i;
				chel[i][0] = a[i] + min(left[i], right[i]);
			}
			sort(chel.begin(), chel.end());
			vector<int> place(n);
			for (int i = 0;i < n; i++) {
				place[i] = i;
				if (i && chel[i][0] == chel[i - 1][0]) {
					place[i] = place[i - 1];
				}
	 			if (chel[i][1] == j) {
	 				cout << max(place[i], mx[j]) + 1<< "\n";
	 				break;
	 			}
			}
			
		}
		
	} else {

		node* root = nullptr;
		node* root1 = nullptr;
		// add a[i] to root
		function<void(int)> add = [&] (int x) {
			auto r = splitv(root, x);
			root = merge(r.first, merge(new node(x), r.second));
		};
		function<void(int)> del = [&] (int x) {
			auto r = splitv(root, x);
			auto r2 = split(r.second, 1);
			root = merge(r.first, r2.second);
		};
		function<void(int)> add1 = [&] (int x) {
			auto r = splitv(root1, x);
			root1 = merge(r.first, merge(new node(x), r.second));
		};
		function<void(int)> del1 = [&] (int x) {
			auto r = splitv(root1, x);
			auto r2 = split(r.second, 1);
			root1 = merge(r.first, r2.second);
		};
		for (int i = 0; i < n; i++) {
			add1(a[i] + i);
		}
		cout << lb(root1, a[0]) + 1 << "\n";
		for (int i = 1;i < n; i++) {
			del1(a[i - 1] + i - 1);
			add(a[i - 1] + (n - 1 - (i - 1)));
			cout << lb(root, a[i] + (n - 1 - i)) + lb(root1, a[i] + i) + 1 << '\n';
		}
		
	}
	

	
}

signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	cerr << "Time: " << TIME << endl;
}