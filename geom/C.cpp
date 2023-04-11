#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld eps = 1e-9;
int sign(ld x) {
	return (x > eps) - (x < -eps);
}

struct point {
	ld x = 0, y = 0;
	point(ld x, ld y): x(x), y(y) {

	}
	point(){}
	point operator+(point other){
		return point(x + other.x, y + other.y);
	}
	point operator-(point other){
		return point(x - other.x, y - other.y);
	}
	ld operator*(point other) {
		return x * other.x + y * other.y;
	}
	ld operator%(point other) {
		return x * other.y - y * other.x;
	}
	ld cross (point a, point b) {
		return (a - *this) % (b - *this);
	}
};

void solve() {

	int n, m, k;
	cin >> n >> m >> k;
	std::vector<point> a(n);
	for (int i = 0; i < n; i++ ){
		int x, y;
		cin >> x >> y;
		a[i] = point(x, y);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		point p(x, y);
		int l = 1, r = n - 1;
		while (r - l > 1) {
			int m = l + r >> 1;
			if (sign((a[m] - a[0]) % (p - a[0])) >= 0) {
				l = m;
			} else  {
				r = m;
			}
		}
		cnt += sign(a[0].cross(a[l], p)) >= 0 && sign(a[l].cross(a[l + 1], p)) >= 0 && sign(a[l + 1].cross(a[0], p)) >= 0;
	}

	cout << (cnt >= k ? "YES" : "NO") << "\n";
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}