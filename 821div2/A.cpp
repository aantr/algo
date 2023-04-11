#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve(){
	
	int n, k;
	cin>>n>>k;
	std::vector<int> a(n);
	vector<int> mx(k);
	for (int i = 0;i < n;i++){
		cin>>a[i];
		mx[i % k] = max(mx[i % k], a[i]);
	}

	cout<< (accumulate(mx.begin(), mx.end(), 0ll))<< "\n";
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}