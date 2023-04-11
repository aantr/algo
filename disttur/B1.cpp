#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

vector<std::vector<int>> gr;
vector<vector<int>> ans;
vector<int> inv;
vector<int> used;

void dfs(int v){
	used[v] = 1;
	ans[v] = {v};
	for (int i : gr[v]){
		if (!used[i]){
			dfs(i);
		}
		for (int j : ans[i]){
			ans[v].push_back(j);
		}
	}
	// calc inv for cur
	for (int i = 0; i < ans[v].size(); i++){
		for (int j = i + 1; j < ans[v].size(); j++){
			inv[v] += ans[v][i] > ans[v][j];
		}
	}

	/*

	// nlogn
	segtree st;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans[v].size(); i++) {
		inv[v] += st.get(0, ans[v][i][1]);
		st.set(ans[v][i][1], 1);
	}

	*/

}

void solve(){

	int n;
	cin >> n;
	gr.assign(n, vector<int> ());
	ans.assign(n, vector<int> ());
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