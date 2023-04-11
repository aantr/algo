#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){
	int n;
	if (!(cin>>n)) return 1;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] --;
	}
	if (n % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	int mn = 1e9;
	vector<vector<int>> posl(65535), posr(65535);
	for (int i = 0; i < n / 2; i++) {
		posl[a[i]].push_back(i);
	}

	for (int i = n - 1; i >= n / 2; i--) {
		posr[a[i]].push_back(n - 1 - i);
	}
	
	for (int i = 0; i < 65535; i++) {
		if ((int)posl[i].size() > 1) {
			mn = min(mn, n / 2 - posl[i][(int)posl[i].size() - 1] + n / 2 - 1 - posl[i][(int)posl[i].size() - 2]);
		}
		if ((int)posr[i].size() > 1) {
			mn = min(mn, n / 2 - posr[i][(int)posr[i].size() - 1] + n / 2 - 1 - posr[i][(int)posr[i].size() - 2]);
		}
		for (int p : posl[i]) {
			auto it = lower_bound(posr[i].begin(), posr[i].end(), p);
			if (it != posr[i].end()) {
				mn = min(mn, *it - p);
			}
		}
		for (int p : posr[i]) {
			auto it = lower_bound(posl[i].begin(), posl[i].end(), p);
			if (it != posl[i].end()) {
				mn = min(mn, *it - p);
			}
		}
	}

	cout << mn << endl;
	return 0;

}

signed main(){
	int t = 1e9;
	// cin>>t;
	while (t--) {
		if (solve()) break;
	}
	cerr << "Time: " << TIME << endl;
}