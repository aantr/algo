#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void ANS(int x) {
	cout << "! " << x << endl;
}

int ASK(int x) {
	cout << "? " << x << endl;
	string res;
	cin >> res;
	return res == "Yes";
}

void solve() {
	int n;
	cin >> n;
	while (1) {

		int l = 1, r = n + 1;
		while (r - l > 1) {
			int m = l + r >> 1;
			int ask1 = ASK(m);

			if (ask1) {
				l = m;
			} else {
				r = m;
			}
		}
		ANS(l);

		string ans;
		cin >> ans;
		if (ans == "Done") {
			break;
		}
	}
}

signed main() {
	int t = 1;
	while (t --> 0) solve();
}