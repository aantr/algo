#include <bits/stdc++.h>
using namespace std;
#define TIME (double) clock() / CLOCKS_PER_SEC

mt19937 rnd(1212);

void solve(){
	int n, p;
	cin >> n >> p;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (p == 2) {
		for (int j = 0; j < n; j++){
			int MX = -1e9;
			for (int mask = 1; mask < 4; mask ++) {
				vector<int> left(n, n), right(n, n);
				if (mask & 1) left[0] = 0;
				if (mask >> 1 & 1) right[n - 1] = 0;
				if (mask == 3) {
					int dst = min(j, n-1-j);
					for (int i = 0; i < n; i++) {
						if (abs(i-j)>=dst) left[i]=0,right[i]=0;
					}
				}
				for (int i = 0; i < n; i++) {
					if (i) left[i] = min(left[i], left[i - 1] + 1);
				}
				for (int i = n - 1; i >= 0; i--) {
					if (i < n - 1) right[i] = min(right[i], right[i + 1] + 1);
				}

				vector<array<int, 2>> chel(n);
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
		 			if (chel[i][1] == j) {
		 				MX = max(MX, place[i]);
		 			}
				}
			}
			cout << MX + 1 << "\n";
		}
		
	} else {

		vector<int> res1 (n);
		for (int j = 0;j < n; j++) {
			vector<array<int, 2>> chel(n);
			for (int i = 0;i < n; i++) {
				chel[i][1] = i;
				chel[i][0] = a[i] + abs(i - j);
			}
			sort(chel.begin(), chel.end());
			vector<int> place(n);
			for (int i = 0;i < n; i++) {
				place[i] = i;
				if (i && chel[i][0] == chel[i - 1][0]) {
					place[i] = place[i - 1];
				}
	 			if (chel[i][1] == j) {
	 				cout << place[i] + 1 << "\n";
	 				break;
	 			}
			}
		}
		
	}
	

	
}

signed main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	cerr << "Time: " << TIME << endl;
}