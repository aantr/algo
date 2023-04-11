#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

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

std::vector<point> hull(std::vector<point> a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<point> h, up;
    for (int i = 0; i < n;i++) {
        if (sign(a[0].cross(a.back(), a[i])) >= 0) {
            while (up.size() > 1 && sign(up[up.size() - 2].cross(up[up.size() - 1], a[i])) >= 0) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (sign(a[0].cross(a.back(), a[i])) <= 0) {
            while (h.size() > 1 && sign(h[h.size() - 2].cross(h[h.size() - 1], a[i])) <= 0) {
                h.pop_back();
            }
            h.push_back(a[i]);
        }
    }
    for (int i = (int)up.size() - 2; i >= 1; i-- ) {
        h.push_back(up[i]);
    }
    return h;
}

void solve() {
    
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = point(x, y, i);
    }
    string s;
    cin >> s;
    vector<int> used(n);
    vector<point> H = hull(a);
    point cur = a[H[0].i];
    used[H[0].i] = 1;
    cout << cur.i + 1 << " ";
    for (int i = 0; i < n - 1;i++) {
        vector<point> lost;
        for (int j = 0; j < n; j++) {
            if (!used[j]) lost.push_back(a[j]);
        }
        H = hull(lost);
        point ans;
        if (i == n - 2 || s[i] == 'R') {
            for (int j = 0; j < H.size(); j++) {
                if (sign(cur.cross(H[j], H[(j - 1 + H.size()) % H.size()]) <= 0) && 
                    sign(cur.cross(H[j], H[(j + 1) % H.size()])) <= 0) {
                    ans = H[j];
                }
            }
        } else {
            for (int j = 0; j < H.size(); j++) {
                if (sign(cur.cross(H[j], H[(j - 1 + H.size()) % H.size()]) >= 0) && 
                    sign(cur.cross(H[j], H[(j + 1) % H.size()])) >= 0) {
                    ans = H[j];
                }
            }
        }
        cout << ans.i + 1 << " ";
        used[ans.i] = 1;
        cur = ans;
    }
    cout << "\n";


    
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}