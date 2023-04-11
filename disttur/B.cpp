#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

mt19937 rnd(1212);

struct node {
	node * l = nullptr, *r = nullptr;
	int v, pr, sz=1;
	node (int v) : v(v){
		pr = rnd();
	}
};

int getsz(node * v){
	if (!v) return 0;
	return v->sz;
}

void upd(node * v){
	if (!v) return;
	v->sz = 1 + getsz(v->l) + getsz(v->r);
}

pair<node*, node*> split(node *root, int k){
	if (!root){
		return {nullptr, nullptr};
	}
	if (getsz(root->l) + 1 <= k) {
		auto [l, r] = split(root->r, k);
		root->r = l;
		upd(root);
		return {root, r};
	} else {
		auto [l, r] = split(root -> l, k);
		root -> l = r;
		upd(root);
		return {l, root};
	}
}

pair<node*, node*> splitv(node *root, int v){
	if (!root){
		return {nullptr, nullptr};
	}
	if (root->v < v) {
		auto [l, r] = splitv(root->r, v);
		root->r = l;
		upd(root);
		return {root, r};
	} else {
		auto [l, r] = splitv(root -> l, v);
		root -> l = r;
		upd(root);
		return {l, root};
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

vector<int> res;
void get(node * v){
	if (!v) return;
	get(v->l);
	res.push_back(v->v);
	get(v->r);
}

vector<std::vector<int>> gr;
vector<node*> ans;
vector<int> inv;
vector<int> used;

void dfs(int v){
	used[v] = 1;
	ans[v] = new node(v); // add el
	for (int i : gr[v]){
		if (!used[i]){
			dfs(i);
		}
		inv[v] += inv[i]; 
		int was = 0;
		if (getsz(ans[i]) > getsz(ans[v])){
			swap(ans[i], ans[v]);
			was = 1;
		}
		res.clear();
		get(ans[i]);
		ans[i] = nullptr;

		if (was) {
			for (int j : res) {
				auto [l, r] = splitv(ans[v], j);
				inv[v] += getsz(l);
				ans[v] = merge(l, r);
			}
		} else {
			for (int j : res) {
				auto [l, r] = splitv(ans[v], j);
				inv[v] += getsz(r);
				ans[v] = merge(l, r);
			}
		}

		for (int j : res){
			auto [l, r] = splitv(ans[v], j);
			ans[v] = merge(l, merge(new node(j), r)); // add el
		}


	}
	

}

void solve(){

	int n;
	cin >> n;
	gr.assign(n, vector<int> ());
	ans.assign(n, nullptr);
	used.assign(n, 0);
	inv.assign(n, 0);
	for (int i = 0; i < n; i++){
		int k;
		cin>>k;
		for (int j = 0; j < k; j++){
			int x;
			cin>>x;
			x--;
			gr[i].push_back(x);
		}
	}

	for (int i = 0;i < n; i++){
		if (!used[i]){
			dfs(i);
		}
	}

	for (int i = 0;i < n;i++)cout << inv[i] << " "; cout<< "\n";

}

signed main(){
	int t = 1;
	// cin >> t;
	while (t--) solve();
}