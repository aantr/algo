#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

mt19937 rnd(1234);

std::vector<std::vector<int>> dp;
vector<vector<int>> parent;

const int K = 2200;
int maxa = K + 1, maxb = K + 1;

int get_move(int a, int b){
	if (a >= maxa || b >= maxb){
		if (a == 1) {
			return 2;
		}
		int A1 = a - 1, B1 = b; // ход 1
		int g = __gcd(A1, B1);
		A1 /= g;
		B1 /= g;
		if (A1 < maxa && B1 < maxb && dp[A1][B1] == 1) {
			return 2;
		}
		return 1;
	}
	return parent[a][b];
}

void solve(){

	int a, b;
	cin>>a>>b;
	if (a * b <= (int) K * K) {
		maxa = a + 1;
		maxb = b + 1;
	}
	parent.assign(maxa, vector<int> (maxb));
	dp.assign(maxa, vector<int> (maxb));
	dp[1][1] = 0;

	for (int i = 1; i < maxa; i++) {
		for (int j = 1; j < maxb; j++) {
			int A = i, B = j;
			if (__gcd(A, B) != 1) continue;
			if (A > 1) parent[A][B] = 1;
			else parent[A][B] = 2;
			if (A > 1){
				int A1 = A - 1, B1 = B;
				int g = __gcd(A1, B1);
				A1 /= g;
				B1 /= g;
				if (dp[A1][B1] == 0){
					parent[A][B] = 1;
					dp[A][B] = 1;
				}
			}
			
			if (B > 1){
				int A1 = A, B1 = B - 1;
				int g = __gcd(A1, B1);
				A1 /= g;
				B1 /= g;
				if (dp[A1][B1] == 0){
					parent[A][B] = 2;
					dp[A][B] = 1;
				}
			}
			
		}
	}

	while (1){

		if (get_move(a, b) == 1){
			cout << "A" << endl;
			a--;
		} else {
			cout << "B" << endl;
			b--;
		}

		int g = __gcd(a, b);
		a /= g;
		b /= g;
		if (a == 1 && b == 1) {
			cerr << "win\n";
			break;
		}

		char inp;
		cin >> inp;
		if (inp == 'A') {
			a--;
		} else {
			b--;
		}
		g = __gcd(a, b);
		a /= g;
		b /= g;
		if (a == 1 && b == 1) {
			cerr << "lose\n";
			break;
		}

	}
	#ifdef ON_PC
	int c;
	cin>>c;
	#endif
}

signed main(){
	int t = 1;
	// cin >> t;
	while (t--) solve();
}