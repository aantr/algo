#include <bits/stdc++.h>
using namespace std;
#define TIME (double) clock() / CLOCKS_PER_SEC

void solve(){
	int n, p;
	cin >> n >> p;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> mn(n + 1, n + 1), mx(n + 1, 0);
	for (int mask = 1; mask < (1 << n); mask ++) {
		vector<array<int, 2>> chel(n);
		vector<int> left(n, n + 1), right(n, n + 1);
		for (int i = 0; i < n; i++) {
			if (i) left[i] = left[i - 1] + 1;
			if (mask >> i & 1) left[i] = 0;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i < n - 1) right[i] = right[i + 1] + 1;
			if (mask >> i & 1) right[i] = 0;
		}
		for (int i = 0;i < n; i++) {
			chel[i][1] = i;
			chel[i][0] = a[i] + min(left[i], right[i]);
		}
		sort(chel.begin(), chel.end());
		vector<int> place(n);
		for (int i = 0;i < n; i++) {
			place[i] = i;
			if (i && chel[i][0] == chel[i - 1][0]) {
				place[i] = place[i - 1];
			}
			mn[chel[i][1]] = min(mn[chel[i][1]], place[i]);
			mx[chel[i][1]] = max(mx[chel[i][1]], place[i]);
		}
	}
	if (p == 1) {
		for (int i = 0;i < n; i++) {
			cout << mn[i] + 1 << "\n";
		}	
	} else {
		for (int i = 0;i < n; i++) {
			cout << mx[i] + 1 << "\n";
		}	
	}
	cout << "\n";
}

signed main (){
	solve();
	cerr << "Time: " << TIME << endl;
}