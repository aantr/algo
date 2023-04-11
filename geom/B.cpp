#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld eps = 1e-9;
int sign(ld x) {
	return (x > eps) - (x < -eps);
}

struct point {
	ld x=0, y=0;
	point(){}
	point(ld x, ld y): x(x), y(y){

	}
	point operator+(point other) {
		return point(x + other.x, y + other.y);
	}
	point operator-(point other) {
		return point(x - other.x, y - other.y);
	}
	ld operator*(point other) {
		return x * other.x + y * other.y;
	}
	ld operator%(point other) {
		return x * other.y - y * other.x;
	}

	ld cross (point x, point y) {
		return (x-*this) % (y-*this);
	}

	ld dot (point x, point y) {
		return (x-*this) * (y-*this);
	}

	ld dist2() {
		return (x) * (x) + (y) * (y);
	}

	ld dist() {
		return sqrtl(dist2());
	}
};

ostream& operator<< (ostream& s, point p) {
	s << p.x << " " << p.y;
	return s;
}

struct line {

	ld a, b, c;
	line (ld a, ld b, ld c): a(a), b(b), c(c) {
		norm();
	}
	line(point x, point y){
		a = x.y - y.y;
		b = y.x - x.x;
		c = -a * x.x - b * x.y;
		norm();
	}

	void norm() {
		ld d = point(a, b).dist();
		a /= d;
		b /= d;
		c /= d;
		if (sign(a) == -1 || sign(a) == 0 && sign(b) == -1) {
			a = -a;
			b = -b;
			c = -c;
		}
	}

	ld dist(point p) {
		return abs((a * p.x + b * p.y + c) / point(a, b).dist());
	}

	int cross (line other, point &res) {
		ld d = point(a, b) % point(other.a, other.b);
		if (sign(d) == 0) return 0;
		res = point(point(b, c) % point(other.b, other.c) / d, 
			point(c, a) % point(other.c, other.a) / d);
		return 1;
	}

	point perp(point p) {
		line P(-b, a, b * p.x - a * p.y);
		point res;
		cross(P, res);
		return res;
	}

};

ld pointseg(point a, point b, point p) {
	if (sign(a.dot(b, p)) >= 0 && sign(b.dot(a, p)) >= 0) {
		return line(a, b).dist(p);
	}
	return min((p - a).dist(), (p - b).dist());
}

ld pointray(point a, point b, point p) {
	if (sign(a.dot(b, p)) >= 0) {
		return line(a, b).dist(p);
	}
	return (p - a).dist();
}

point get_point(line l) {
	ld x = rand();
	if (sign(l.b) == 0) {
		return point(-l.c / l.a, rand());
	}
	return point(x, (l.c - l.a * x) / l.b);
}

ld segray(point a, point b, point c, point d) {
	point res;
	if (line(a, b).cross(line(c, d), res) && 
					sign(a.dot(b, res)) >= 0 && 
					sign(b.dot(a, res)) >= 0 && 
					sign(c.dot(d, res)) >= 0) {
		return 0;
	} else {
		return min({pointseg(a, b, c), pointray(c, d, a), pointray(c, d, b)});
	}
}

ld segseg(point a, point b, point c, point d) {
	point res;
	if (line(a, b).cross(line(c, d), res) && 
					sign(a.dot(b, res)) >= 0 && 
					sign(b.dot(a, res)) >= 0 && 
					sign(c.dot(d, res)) >= 0 && 
					sign(d.dot(c, res)) >= 0) {
		return 0;
	} else {
		return min({pointseg(a, b, d), pointseg(a, b, c), pointseg(c, d, a), pointseg(c, d, b)});
	}
}
void solve() {

	int x, y;
	cin >> x >> y;
	point a(x, y);
	cin >> x >> y;
	point b(x, y);
	cin >> x >> y;
	point c(x, y);
	cin >> x >> y;
	point d(x, y);
	cout << fixed << setprecision(7);
	cout << (a-c).dist() << "\n";
	cout << pointseg(c, d, a) << "\n";
	cout << pointray(c, d, a) << "\n";
	cout << line(c, d).dist(a) << "\n";
	cout << pointseg(a, b, c) << "\n";
	point res;
	cout << segseg(a, b, c, d) << "\n";
	cout << segray(a, b, c, d) << "\n";
	if (line(a, b).cross(line(c, d), res) && sign(a.dot(b, res))>=0 && sign(b.dot(a, res))>=0) {
		cout << 0.0 << "\n";
	} else {
		cout << min(line(c, d).dist(a), line(c, d).dist(b)) << "\n";
	}
	cout << pointray(a, b, c) << "\n";
	cout << segray(c, d, a, b) << "\n";
	if (line(a, b).cross(line(c, d), res) && sign(a.dot(b, res))>=0 && sign(c.dot(d, res))>=0) {
		cout << 0.0 << "\n";
	} else {
		cout << min(pointray(a, b, c), pointray(c, d, a)) << "\n";
	}
	if (line(a, b).cross(line(c, d), res) && sign(a.dot(b, res)) >= 0) {
		cout << 0.0 << "\n";
	} else {
		cout << line(c, d).dist(a) << "\n";
	}
	cout << line(a, b).dist(c) << "\n";
	if (line(a, b).cross(line(c, d), res) && sign(c.dot(d, res)) >= 0 && sign(d.dot(c, res)) >= 0) {
		cout << 0.0 << "\n";
	} else  {
		cout << min(line(a, b).dist(c), line(a, b).dist(d)) << "\n";
	}
	if (line(a, b).cross(line(c, d), res) && sign(c.dot(d, res)) >= 0) {
		cout << 0.0 << "\n";
	} else {
		cout << line(a, b).dist(c) << "\n";
	}
	if (line(a, b).cross(line(c, d), res)) {
		cout << 0.0 << "\n";
	} else {
		cout << line(a, b).dist(line(c, d).perp(point(0, 0))) << "\n";
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