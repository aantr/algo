#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int maxn = 1e6 + 5;
int a[maxn];

void solve() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i > 1; i--) {
		int op = max(0ll, a[i - 1] - a[i]);
		a[i - 1] -= op;
		a[i - 2] -= op;
	}

	for (int i = 0; i < n - 2; i++) {
		int op = max(0ll, a[i] - a[i + 1]);
		a[i + 1] += op;
		a[i + 2] += op;
	}

	// for (int i = 0; i < n ;i++) cout << a[i] << " "; cout << "\n";

	cout << (a[n - 2] <= a[n - 1] ? "Yes" : "No") << endl;

}

signed main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}