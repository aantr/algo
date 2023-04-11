#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll

int get(vector<int> a) {
	int n = a.size();
	for (int x = 0; x < 1000; x++) {
		vector<int> b = a;
		for (int i = 0; i < n; i++) {
			b[i] ^= x;
		}
		if (is_sorted(b.begin(), b.end())) {
			return x;
		}
	}
	return -1;
}

void solve() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i  =0; i  < n; i++) cin >> a[i];
	cout << get(a) << "\n";
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--;
		a[x] = y;
		cout << get(a) << "\n";
	}

}	


signed main () {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t --> 0) solve();
	cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << "\n";
}