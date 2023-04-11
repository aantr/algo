#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

void solve(){
	
	int n, k;
	cin >> n >> k;
	std::vector<int> a(k), b(n);
	for (int i = 0; i < k; i++) cin >> a[i];
	if (k == 1) {
		cout << "Yes\n";
		return;
	}
	int ok = 1;
	for (int i = 1; i < k; i++) b[n - k + i] = a[i] - a[i - 1];
	int s = 0;
	for (int i = 0; i < n - k + 1; i++) b[i] = b[n - k + 1], s += b[i];
	ok &= s >= a[0];
	for (int i = 0; i < n - 1; i++) {
		ok &= b[i + 1] >= b[i];
	}

	cout << (ok ? "YES\n" : "NO\n");

}

signed main(){
	int t = 1;
	cin >> t;
	while (t--){
		solve();
	}
	cerr << "Time: " << TIME << endl;
}