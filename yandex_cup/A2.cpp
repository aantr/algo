#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

int get(vector<int> a) {
	int n = a.size();
	int ans = 0;
	vector<int> groups(a.size());
	groups[0] = 1;
	for (int i = 29; i >= 0; i--) {
		int count = 1;
		int bit = -1;
		for (int j = 0; j < n; j++){

			if (groups[j]) count = 1;

			if (j && !groups[j] && (a[j] >> i & 1) != (a[j - 1] >> i & 1)) {
				count ++;
				if (count > 2) {
					return -1;
				}
				if ((a[j] >> i & 1) == 0) {
					if (bit == -1) {
						bit = 1;
					} else if (bit != 1) {
						return -1;
					}
				} else {
					if (bit == -1) {
						bit = 0;
					} else if (bit != 0) {	
						return -1;
					}
				}
				groups[j] = 1;
			}

		}
		if (bit == 1) {
			ans |= 1 << i;
		}
	}
	return ans;
}

void solve() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = get(a);
	cout << ans << endl;
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--;
		a[x] = y;
		
	}



}	


signed main () {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t --> 0) solve();
	cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << "\n";
}