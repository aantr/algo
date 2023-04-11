#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld eps = 1e-10;
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
	point operator* (ld other) {
		return point(x * other, y * other);
	}
	ld dist2() {return (x * x) + (y * y);}
	ld dist() {return sqrtl(dist2());}
	point norm() {
		ld d = dist();
		if (sign(d) == 0) return point();
		return point(x / d, y / d);
	}
	point perp() {
		return point(-y, x);
	}
};

ostream& operator<<(ostream& o, point p) {
	o << p.x << " " << p.y;
	return o;
}

/*



*/

/*

(x - xa) ^ 2 + (y - ya) ^ 2 = ra ^ 2
(x - xb) ^ 2 + (y - yb) ^ 2 = rb ^ 2

(2x - xa -xb) (-xa + xb) + (2y -ya - yb) (-ya + yb) = ra ^ 2 - rb ^ 2
x2 -2 xa x + xa2 + y2 - 2 ya y + ya2 = ra2
x2 -2 xb x + xb2 + y2 - 2 yb y + yb2 = rb2

x (-2 xa + 2xb) + y (-2 ya + 2yb) = ra2 - rb2 + xa2 + ya2 - xb2 - yb2


*/

void solve() {
	cout << fixed << setprecision(10);
	ld xa, ya, ra, xb, yb, rb;
	cin >> xa >> ya >> ra >> xb >> yb >> rb;
	ld d = (point(xa, ya) - point(xb, yb)).dist();
	if (sign(d) == 0) {
		cout << (ra == rb ? 3 : 0) << "\n";
	} else {
		ld x = (rb*rb-ra*ra+(point(xa, ya) - point(xb, yb)).dist2()) / (2*d);
		if (sign(rb * rb - x * x) < 0) {
			cout << 0 << "\n";
			return;
		} else if (sign(rb * rb - x * x) == 0) {
			cout << 1 << "\n";
			point M = (point(xa, ya) - point(xb, yb)).norm() * x + point(xb, yb);
			cout << M << endl;
			return;
		}
		ld y = sqrtl(rb * rb - x * x);
		cout << 2 << "\n";
		point M = (point(xa, ya) - point(xb, yb)).norm() * x + point(xb, yb);
		point V = (point(xa, ya) - point(xb, yb)).perp().norm() * y;
		cout << M + V << "\n" << M + V * -1 << "\n";
	}
	
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}