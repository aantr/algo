#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

mt19937 rnd(1234);

void solve(){

	int n;
	cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin>>a[i];
	b[0] = a[0];
	for (int i = n - 1; i >= 1; i--) a[i] = a[i] - a[i - 1];
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	do {

		int ok = 1;
		vector<int> need(n); // сумма всех элеменов левее где A <, + 1
		need[0] = 1;
		for (int i = 1; i < n; i++) {
			need[i] += 1;
			for (int j = 0; j < i; j++) {
				if (p[i] > p[j]){
					need[i] += need[j];
				}
			}
		}

		if (need == a){
			for (int i = 0; i < n; i++) 
				cout << p[i] << " "; cout << "\n";
			cout << "\n";
		}

	} while (next_permutation(p.begin(), p.end()));
	
}

/*

1 1
1 2

1 1 2 непонятно
1 1 3

1 2 5 6
1 1 3 1

1 3 5 9 11 21
1 2 2 4 2 10

1 4 2 3 6 5



*/


signed main(){
	int t = 1;
	// cin >> t;
	while (t--) solve();
}