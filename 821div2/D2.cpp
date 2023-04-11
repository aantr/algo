#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    std::vector<int> a;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i]) a.push_back(i);
    if (x < y) {
    	int n = a.size();

    	if (a.size() % 2 != 0) {
       		cout << -1 << '\n';
	        return;
	    }
    	vector<vector<int>> dp(n + 1, vector<int> (2, 1e18)); // стоимость для префикса. если нечетный то один элемент удалим за у
    	dp[0][0] = 0;
    	for (int i = 1 ; i <= n ; i++){
    		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
    		if (i % 2 == 1) dp[i][0] += y;
    		if (i > 1) dp[i][1] = min(dp[i - 2][0], dp[i - 2][1]) + min((a[i - 1] - a[i - 2]) * x, (int)y);
    	}

    	cout << min(dp[n][0], dp[n][1]) << "\n";

    	return;
    }
    if (a.size() % 2 != 0) {
        cout << -1 << '\n';
        return;
    }
    if (!a.size()) {
        cout << 0 << "\n";
        return;
    }
    if (a.size() == 2) {
    	if (a[0] + 1 != a[1]){
    		cout << y << "\n";
    		return;
    	}
        if (y * 2 > x) {
            cout << x << "\n";
        } else {
        	if (a[0] >= 2 || (n - 1 - a[1]) >= 2) {
        		cout << y * 2 << "\n";
        	} else {
        		cout << x << "\n";
        	}
        }

    } else {
        cout << y * a.size() / 2 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}