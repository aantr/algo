#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

void solve(){
	
	int n;
	cin >> n;
	std::vector<int> a(n), b(n);
	deque<int> a1, a2;
	for (int i = 0;i < n; i++) cin >> a[i];
	for (int i = 0;i < n; i++) cin >> b[i];
	int ans = 0;
	for (int i = 0; i < n; i++) ans += b[i];
	for (int i = 0;i < n; i++) {
		if (a[i] == 0) {
			a1.push_back(b[i]);
		} else{
			a2.push_back(b[i]);
		}
	}
	sort(a1.rbegin(), a1.rend());
	sort(a2.rbegin(), a2.rend());
	
	int v1 = 0, v2 = 0;
	int i = 0, j = 0;
	int m = 1;
	while (a1.size() > 0) {
		if (m == 1) {
			if (j >= a2.size()) break;
			v1 += a2[j];
			j++;
		} else {
			if (i + 1 >= a1.size()) break;
			v1 += a1[i];
			i++;
		}
		m ^= 1;
	}
	i = 0;
	j = 0;
	m = 0;
	while (a2.size() > 0) {
		if (m == 1) {
			if (j + 1 >= a2.size()) break;
			v2 += a2[j];
			j++;
		} else {
			if (i >= a1.size()) break;
			v2 += a1[i];
			i++;
		}
		m ^= 1;
	}
	// cout << v2 << endl;
	cout << ans + max(v1, v2) << "\n";
}

signed main(){
	int t = 1;
	cin >> t;
	while (t--){
		solve();
	}
	cerr << "Time: " << TIME << endl;
}