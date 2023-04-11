#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve(){
	
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0;i < n;i++){
		cin>>a[i];
	}
	vector<array<int, 2>> ans;
	int mx = 0;
	for (int i = 1; i < n; i++){
		if (a[i] % 2 == a[0] % 2) mx = i;
	}

	for (int i = 0; i < mx; i++){
		if (a[i] % 2 == a[mx] % 2) {
			ans.push_back({i, mx});
		}
	}

	for (int i = 1; i < n; i++){
		if (a[i] % 2 != a[0] % 2) {
			ans.push_back({0, i});
		}
	}

	cout<<ans.size() << "\n";
	for (auto i : ans){
		cout<<i[0] + 1<<" "<<i[1] + 1<<"\n";
	}


}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}