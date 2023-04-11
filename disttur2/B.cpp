#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC

const int inf = INT_MAX;

template<std::size_t N>
bool operator<(const std::bitset<N>& x, const std::bitset<N>& y)
{
    for (int i = N-1; i >= 0; i--) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}

int solve(){
	
	int r, s;
	if (!(cin >> r)) return 1;
	cin >> s;
	vector<string> field(r);
	for (int i = 0;i < r; i++){
		cin >> field[i];
	}

	vector<vector<vector<int>>> dp(r, vector<vector<int>> (s, vector<int> (r + 1, -inf))), 
								parent(r, vector<vector<int>> (s, vector<int> (r + 1, -1)));
	vector<vector<bitset<30>>> cur(s, vector<bitset<30>> (r + 1)), curT(s, vector<bitset<30>> (r + 1));

	for (int i = 0;i < s;i++) {
		if (field[r - 1][i] == 'M') {
			dp[r - 1][i][0] = 0;
		}
	}
	for (int i = r - 2; i >= 0; i--) {
		for (int j = 0; j < s; j++) {
			for (int bal = 0; bal < r + 1; bal ++) {
				int v = 0;
				int cnt = 0;
				if (field[i][j] == '(') v = 1, cnt++;
				if (field[i][j] == ')') v = -1, cnt++;
				for (int d = -1; d <= 1; d++){
					int J = j + d;
					if (J >= 0 && J < s && bal - v >= 0 && bal - v < r + 1 && field[i + 1][J] != '*') {
						int V = dp[i + 1][J][bal - v] + cnt;
						if (dp[i][j][bal] < V || dp[i][j][bal] == V && cur[J][bal - v] < curT[j][bal]) {
							dp[i][j][bal] = V;
							parent[i][j][bal] = J;
							curT[j][bal] = cur[J][bal - v];
						}
					}
				}
				if (v == 1 && curT[j][bal].size() < 30) curT[j][bal] += '(';
				if (v == -1 && curT[j][bal].size() < 30) curT[j][bal] += ')';
			}
		}
		cur = curT;
		curT.assign(s, vector<bitset<30>> (r + 1));
	}

	int ans = -inf;
	vector<array<int, 2>> poses;
	vector<string> SS;
	for (int i = 0; i < s; i++){
		if (dp[0][i][0] > ans) {
			ans = dp[0][i][0];
			poses = {{0, i}};
		} else if (dp[0][i][0] == ans) {
			poses.push_back({0, i});
		}
	}
	for (int i = 0; i < s; i++){
		for (int j = 0; j < r; j ++){
			if (field[j][i] == '*') {
				if (dp[j][i][0] > ans) {
					ans = dp[j][i][0];
					poses = {{j, i}};
				} else if (dp[j][i][0] == ans) {
					poses.push_back({j, i});
				}
			}
		}
	}

	cout << ans << endl;
	for (auto pos : poses) {
		string S;
		int bal = 0;
		while (pos[0] < r - 1) {
			int v = 0;
			if (field[pos[0]][pos[1]] == '(' || field[pos[0]][pos[1]] == ')') {
				S += field[pos[0]][pos[1]];
				if (field[pos[0]][pos[1]] == '(') v --;
				else v ++;
			}
			pos[1] = parent[pos[0]][pos[1]][bal];
			pos[0]++;
			bal += v;
		}
		reverse(S.begin(), S.end());
		SS.push_back(S);
	}
	cout << *min_element(SS.begin(), SS.end()) << endl;
	

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