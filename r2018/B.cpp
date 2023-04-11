#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double)clock() / CLOCKS_PER_SEC

int solve() {
    int n;
    if (!(cin >> n))
        return 1;
    vector<int> a(n);
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        idx[a[i]] = i;
    }
    vector<array<int, 2>> ans;
    function<void(int, int)> do_op = [&](int l, int r) {
        vector<int> el{a.begin() + l, a.begin() + r + 1};
        for (int i = 0; i < r - l + 1; i++) {
            if (i % 2 == 0) {
                a[l + (r - l + 1) / 2 + i / 2] = el[i];
                idx[a[l + (r - l + 1) / 2 + i / 2]] = l + (r - l + 1) / 2 + i / 2;
            } else {
                a[l + i / 2] = el[i];
                idx[a[i / 2 + l]] = i / 2 + l;
            }
        }
    };

    for (int i = 0; i < n; i++) {
        while(a[i] != i){
        	int start = i;
	        if ((idx[i] - start) % 2 == 0) {
	            start++;
	        }
	        int end = idx[i];
	        // cout << start << " " << end << endl;
	        ans.push_back({start, end});
	        do_op(start, end);
	    }
    }

    for (int i = 0; i < n; i++) {
 		assert(a[i] == i);
 	}

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << endl;
    }

    return 0;
}

signed main() {
    int t = 1e9;
    // cin >> t;
    while (t--) {
        if (solve())
            break;
    }
    cerr << "Time: " << TIME << endl;
}