#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){

	int n;
	cin>>n;
	if (n % 2 == 0) cout<<n * (n - 1) - n<<"\n";
	else cout<< n * (n - 1)<<"\n";

}

signed main(){
	int t=1;
	//cin>>t;
	#ifndef ON_PC
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	#endif
	while (t--){
		solve();
	}
}