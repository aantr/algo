#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {

	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	k--;
	std::vector<string> v;

	/*for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n - 1 - i; j++) {
			v.push_back(min({s.substr(0, i), s.substr(i, j), s.substr(i + j, n - i - j)}));
		}
	}*/

	for (int i = 1; i <= n - 1; i++) {
		v.push_back(min({s.substr(0, i), s.substr(i, n - i)}));
	}

	sort(v.rbegin(), v.rend());
	/*for (auto i : v) {
		cout << i << " ";
	}
	cout << "\n";*/
	cout << v[k] << "\n";

}

signed main () {
	int t = 1;
	while (t--) {
		solve();
	}
}