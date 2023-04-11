#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve(){
	
	int n;
	cin>>n;
	vector<int> a(n);
	vector<array<int, 2>> b(n);
	for (int i= 0 ;i < n;i++){
		cin>>a[i];
		b[i][0] = a[i];
		b[i][1] = i;
	}
	vector<array<int, 2>> ans;
	sort(b.rbegin(), b.rend());

	for (int i = 0;i < n;i++){
		if (i != 0 && b[i][1] > b[i - 1][1]) continue;
		int prev = n;
		if (i) prev = b[i - 1][1];
		int was = 0;
		for (int j = 0;j < prev; j++){
			if (b[i][0] % 2)
		}

	}

}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}