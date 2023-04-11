#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

struct point{
    ld x, y;
    point(){
        x=0;
        y=0;
    }
    point (ld x, ld y) : x(x), y(y){

    }

    point operator-(point p){
        return point(x - p.x, y - p.y);
    }

    ld cross(point p){
        return x * p.y - y * p.x;
    }

    ld cross(point a, point b){
        return (a - point(x, y)).cross(b - point(x, y));
    }

    point perp(){
        return point(-y, x);
    }

    bool operator < (point p){
        return tie(x, y) < tie(p.x, p.y);
    }

    friend ostream& operator<<(ostream& os, point p) {
        return os << "(" << p.x << "," << p.y << ")"; }


};
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
#define P point
#define sz(x) (x.size())
#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0
template <class P> int extrVertex(vector<P>& poly, P dir) {
    int n = sz(poly), lo = 0, hi = n;
    if (extr(0)) return 0;
    while (lo + 1 < hi) {
        int m = (lo + hi) / 2;
        if (extr(m)) return m;
        int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);
        (ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;
    }
    return lo;
}

#define cmpL(i) sgn(a.cross(poly[i], b))
template <class P>
array<int, 2> lineHull(P a, P b, vector<P>& poly) {
    int endA = extrVertex(poly, (a - b).perp());
    int endB = extrVertex(poly, (b - a).perp());
    if (cmpL(endA) < 0 || cmpL(endB) > 0)
        return {-1, -1};
    array<int, 2> res;
    for (int i=0;i<2;i++){
        int lo = endB, hi = endA, n = sz(poly);
        while ((lo + 1) % n != hi) {
            int m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;
            (cmpL(m) == cmpL(endB) ? lo : hi) = m;
        }
        res[i] = (lo + !cmpL(hi)) % n;
        swap(endA, endB);
    }
    if (res[0] == res[1]) return {res[0], -1};
    if (!cmpL(res[0]) && !cmpL(res[1]))
        switch ((res[0] - res[1] + sz(poly) + 1) % sz(poly)) {
            case 0: return {res[0], res[0]};
            case 2: return {res[1], res[1]};
        }
    return res;
}

int solve(){
    
    int n, m;
    if (!(cin>>n))return 1;
    cin>>m;
    vector<array<int, 3>> q(n);
    for (int i=0;i<n;i++)cin>>q[i][0]>>q[i][1]>>q[i][2];
    vector<point> p;
    for (int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        point pp(x, y);
        p.push_back(pp);
    }
    sort(p.begin(), p.end());
    vector<point> hull(m + 2);
    int t=0, s;
    point A = p[0], B = p.back();
    for (int i=0;i<m;i++){
        if (A.cross(B, p[i]) <= 0){
            hull[t++] = p[i];
            while (t > 2 && hull[t - 3].cross(hull[t - 2], hull[t - 1]) <= 0) t--, hull[t - 1] = p[i];
        }
    }
    t--;
    s=t;
    for (int i=m-1;i>=0;i--){
        if (A.cross(B, p[i]) >= 0){
            hull[t++] = p[i];
            while (t-s > 2 && hull[t - 3].cross(hull[t - 2], hull[t - 1]) <= 0) t--, hull[t - 1] = p[i];
        }
    }
    t--;
    hull = {hull.begin(), hull.begin() + t};
    if (p.size() == 1)hull = p;

    vector<int> ans;
    for (int i=0;i<n;i++){
        auto [A, B, C] = q[i];
        point a, b;
        if (B == 0){
            a = point(-C / A, 0);
            b = point((-C - B * 1e6) / A, 1e6);
        }else{
            a = point(0, -C/B);
            b = point(1e6, (-C - A * 1e6) / B);
        }
        auto res = lineHull(a, b, hull);
        if (res[0] != -1){
            ans.push_back(i + 1);
        }
    }
    cout<<ans.size()<<endl;
    for (int i : ans)cout<<i<<" ";cout<<"\n";
    return 0;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1e9;
    // cin>>t;
    #ifndef ON_PC
    /*freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);*/
    #endif
    while (t--){
        if (solve()) break;
    }
    cerr<<"time: "<<(double)clock() / (double)CLOCKS_PER_SEC<<"\n";
}