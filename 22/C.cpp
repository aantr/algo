#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>>(101, vector<vector<int>> (2, vector<int> (2))));


void build() {
	for (int i = 0; i < 101; i++) dp[i][0][0][0] = 1, dp[i][0][1][0] = 0, dp[i][0][0][1] = 1, dp[i][0][1][1] = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			for (int k = 0; k < 2; k++) {
				for (int q = 0; q < 2; q++) {
					if (q == 0){
						if (i) {
							if (dp[i - 1][j][k][1 - q] == 1) dp[i][j][k][q] = 1;
						}
						if (dp[i][j - 1][1 - k][1 - q] == 1) dp[i][j][k][q] = 1;
					} else {
						dp[i][j][k][q] = 1;
						if (i) {
							if (dp[i - 1][j][k][1 - q] == 0) dp[i][j][k][q] = 0;
						}
						if (dp[i][j - 1][k][1 - q] == 0) dp[i][j][k][q] = 0;
					}
					
				}
			}
		}
	}
}

void solve(){
	
		
	int n;
	cin >> n;
	int v[2] = {};
	for (int i = 0; i < n; i++) {
		int x;
		cin>>x;
		x+=1e9+6;
		v[x%2]++;
	}
	cout << (dp[v[0]][v[1]][0][0] ? "Alice\n" : "Bob\n");
}

signed main(){
	build();
	int t = 1;
	cin >> t;
	while (t--){
		solve();
	}
	cerr << "Time: " << TIME << endl;
}