#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef unsigned long ul;
#define int ll	
#define TIME (double) clock() / CLOCKS_PER_SEC

using ordered_set = tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>;

void solve(){	
	
	int n, p;
	cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> p;
	ordered_set seg;
	int ans = 0;
	int pref = 0;
	for (int i = 0; i < n; i++) {
		pref += a[i] - p;
		seg.insert({a[i] - p - pref, i});
		ans += seg.size() - seg.order_of_key({-pref, -1000000000});
	}
	cout << ans << '\n';

}

signed main(){
	int t = 1;
	while (t--){
		solve();
	}
	cerr << "Time: " << TIME << endl;
}