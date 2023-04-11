#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ul;
#define int ll	
#define TIME (double) clock() / CLOCKS_PER_SEC

void solve(){	
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int t, l, r, k;
		cin >> t >> l >> r >> k;
		if (t == 0) {
			l--;
			for (int i = l; i < r; i++) a[i] = k;
		} else {
			l--;
			r--;
			vector<int> s, s1;
			for (int i = l; i < l + k; i++) {
				s.push_back(a[i]);
			}
			for (int i = r; i < r + k; i++) {
				s1.push_back(a[i]);
			}
			cout << (s == s1 ? '+' : '-');
		}
	}

}

signed main(){
	int t = 1;
	while (t--){
		solve();
	}
	cerr << "Time: " << TIME << endl;
}