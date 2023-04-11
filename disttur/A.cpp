#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

void solve(){

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<array<int, 2>> b(n);
	for (int i = 0; i < n; i++){
		b[i][0]=a[i];
		b[i][1]=i;
	}
	sort(b.begin(), b.end());
	int l=0,r=1,cur=1;
	for (int i = 1; i < n; i++){
		if (b[i][0] - b[i - 1][0] > m){
			if (cur > r-l){
				r = i;
				l = r - cur;
			}
			cur = 0;
		}
		cur++;
	}

	if (cur > r-l){
		r = n;
		l = r - cur;
	}

	cout << r-l << "\n";
	for (int i = l;i < r; i++){
		cout<< b[i][1] + 1 << " ";
	}

}

signed main(){
	int t = 1;
	// cin >> t;
	while (t--) solve();
}