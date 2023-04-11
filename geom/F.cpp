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
    ld dot (point a, point b) {
        return (a - *this) * (b - *this);
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

a x.x + b x.y + c = 0
a y.x + b y.y + c = 0

a (x.x - y.x) + b (x.y -y.y) = 0

*/
struct line {

    ld a, b, c;
    line (point x, point y) {
        a = x.y -y.y;
        b = -(x.x - y.x);
        c = -a * x.x - b * x.y;
    }

    ld dist(point p) {
        return abs(a * p.x + b * p.y + c) / point(a, b).dist();
    }

};

ld dug(point c, point A, point B, ld r){
    ld a = atan2(c.cross(A, B), c.dot(A, B));
    return abs(r * a);
}

pair<point, point> kas(point a, point c, ld r) {
    ld d = (a - c).dist();
    ld x = r * r / d;
    ld y = sqrtl(r * r - x * x);
    point M = (a - c).norm() * x + c;
    point V = (a - c).norm().perp();
    return {M + V * y, M - V * y};
}

void solve() {
    
    cout << fixed << setprecision(5);
    int x, y;
    cin >> x >> y;
    point a(x, y);
    cin >> x >> y;
    point b(x, y);
    cin >> x >> y;
    point c(x, y);
    ld r;
    cin>>r;
    if (line(a, b).dist(c) >= r || sign(a.dot(b, c)) <= 0 || sign(b.dot(a, c)) <= 0) {
        cout << (a - b).dist() << "\n";
        return;
    }
    auto [A, B] = kas(a, c, r);
    auto [C, D] = kas(b, c, r);
    cout << min((a-B).dist() + (b-C).dist() + dug(c, C, B, r), 
            (a - A).dist() + (b - D).dist() + dug(c, A, D, r)) << "\n";
    
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}