#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll

ld eps = 1e-9;
int sign(ld x) {
    return (x > eps) - (x < -eps);
}

struct point {
    ld i;
    ld x = 0, y = 0;
    point(ld x, ld y, int i = 0): x(x), y(y), i(i) {

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
    int operator<(point other) {
        return sign(x - other.x) == -1 || sign(x - other.x) == 0 && sign(y - other.y) == -1;
    }
};

ostream& operator<<(ostream& o, point p) {
    o << p.x << " " << p.y;
    return o;
}

void solve() {
    
    int n;
    cin >> n;
    std::vector<point> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = point(x, y, i);
    }
    sort(a.begin(), a.end());
    vector<point> hull, up;
    for (int i = 0; i < n; i++) {
        if (sign(a[0].cross(a.back(), a[i])) >= 0) {
            while (up.size() > 1 && sign(up[up.size() - 2].cross(up[up.size() - 1], a[i])) >= 0) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (sign(a[0].cross(a.back(), a[i])) <= 0) {
            while (hull.size() > 1 && sign(hull[hull.size() - 2].cross(hull[hull.size() - 1], a[i])) <= 0) {
                hull.pop_back();
            }
            hull.push_back(a[i]);
        }
    }
    reverse(up.begin(), up.end());
    for (int i = 1; i < (int)up.size()-1; i++) {
        hull.push_back(up[i]);
    }
    vector<int> used(n);
    for (int i = 0; i < hull.size(); i++) {
        used[hull[i].i] = 1;
    }

    vector<point> hull2;
    up.clear();

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (sign(a[0].cross(a.back(), a[i])) >= 0) {
            while (up.size() > 2 && sign(up[up.size() - 2].cross(up[up.size() - 1], a[i])) >= 0) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (sign(a[0].cross(a.back(), a[i])) <= 0) {
            while (hull2.size() > 2 && sign(hull2[hull2.size() - 2].cross(hull2[hull2.size() - 1], a[i])) <= 0) {
                hull2.pop_back();
            }
            hull2.push_back(a[i]);
        }
    }

    reverse(up.begin(), up.end());
    for (int i = 1; i < (int)up.size()-1; i++){
        hull2.push_back(up[i]);
    }

    int cnt = n - accumulate(used.begin(), used.end(), 0ll);
    int p = hull.size() * cnt, q = n;
    int N = hull2.size();
    if (!hull2.size()) {
        p += n * (n - 1);
    } else {
        int l = 0, r = 0;
        int I = 0;
        cnt = 0;

        function<int(int, int, int)> is_kas = [&](int i, int x, int y) {
            return hull2.size() == 1 || 
                    sign((hull[y] - hull[x]) % (hull2[(i + 1) % hull2.size()] - hull2[i])) >= 0 && 
                    sign((hull[y] - hull[x]) % (hull2[(i - 1 + hull2.size()) % hull2.size()] - hull2[i])) > 0;
        };
        for (int i = 0; i < hull2.size(); i++) {
            if (is_kas(i, 0, 2)) {
                l = i, r = i;
            }
        }
        while (sign(hull[0].cross(hull[2], hull2[(l-1+hull2.size())%hull2.size()])) < 0 && (l-1+hull2.size())%hull2.size() != r){
            l = (l-1+hull2.size())%hull2.size();
        }

        while (sign(hull[0].cross(hull[2], hull2[(r+1)%hull2.size()])) < 0 && (r+1)%hull2.size() != l){
            r = (r + 1)%hull2.size();
        }

        if (sign(hull[0].cross(hull[2], hull2[r])) < 0) {
            cnt = r - l + 1;
        } else {
            cnt = 0;
        }
        p += (int)hull.size() - 1 + cnt;

        int was_kas;
        for (int i = 1; i < hull.size(); i++, I = (I + 1) % hull.size()) {
            was_kas = 0;
            while (1) {
                if (is_kas(r, i, (i + 2) % hull.size())) was_kas = 1;
                if (is_kas(r, i, (i + 2) % hull.size()) && sign(hull[i].cross(hull[(i + 2) % hull.size()], hull2[r])) >= 0) break;
                if (was_kas && sign(hull[i].cross(hull[(i + 2) % hull.size()], hull2[r])) >= 0) break;
                if ((r + 1) % hull2.size() == l) break;
                r = (r + 1) % hull2.size();
            }

            while (1) {
                if (sign(hull[i].cross(hull[(i + 2) % hull.size()], hull2[r])) < 0) break;
                if (is_kas(l, i, (i + 2) % hull.size()) && sign(hull[i].cross(hull[(i + 2) % hull.size()], hull2[l])) >= 0) break;
                if ((l + 1) % hull2.size() == r) break;
                l = (l + 1) % hull2.size();

            }
            if (sign(hull[i].cross(hull[(i + 2) % hull.size()], hull2[r])) < 0) {
                cnt = r - l + 1;
            } else {
                cnt = 0;
            }
            p += (int)hull.size() - 1 + cnt;
        }
    }
    
    int g = __gcd(p, q);
    p /= g, q /= g;
    cout << p << "/" << q << "\n";
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}