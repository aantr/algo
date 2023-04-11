#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 10e6 + 100;
std::vector<int> gr[maxn];
int n, q;
vector<int> a;
// vector<int> binup [21];
int parent[maxn];
int h[maxn];
int lr[maxn][2];
int get(int r, int c) {
    return r * 3001 + c;
}
int K;
vector<array<int, 4>> Q;

void dfs(int v, int p = -1) {
    if (p == -1) {
        h[v] = 0;
        parent[v] = v;
    } else {
        parent[v] = p;
        h[v] = h[p] + 1;
    }
    for (int i : gr[v]) {
        if (i == p) continue;
        dfs(i, v);
    }
}

int lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    while (h[a] > h[b]) a = parent[a];
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void slv1() {

    
    array<int, 2> cur = {};
    vector<int> was(n);
    for (int i = 0; i <= n; i++) {
        cur = {};
        for (int j = 0; j < n; j++) {
            int v, v1;
            if (!was[j]) {
                lr[get(cur[0], cur[1])][1] = 1;
                cur[1]++;
            } else {
                lr[get(cur[0], cur[1])][0] = 1;
            }
            
            cur[0]++;
        }
        if (i < n) {
            was[a[i] - 1] = 1;
        }
    }

    for (int i = 0; i < maxn; i++) {
        if (lr[i][0]) {
            gr[i].push_back(i + 3001);
        }
        if (lr[i][1]) {
            gr[i].push_back(i + 3001 + 1);
        }
    }

    dfs(0);

    for (int i = 0; i < q; i++) {
        auto [r1, c1, r2, c2] = Q[i];
        int v = get(r1, c1), v1 = get(r2, c2);

        int LCA = lca(v, v1);
        cout << LCA / 3001 << " " << LCA % 3001 << "\n";

    }

}

void slv2() {
    for (int i = 0; i < q; i++) {
        auto [r1, c1, r2, c2] = Q[i];
        int d1 = r1 - c1, d2 = r2 - c2;
        if (d1 < d2) {
            cout << d1 << " " << 0 << "\n";
        } else if (d2 < d1){
            cout << d2 << " " << 0 << "\n";
        } else {
            if (r1 < r2)
                cout << r1 << " " << c1 << "\n";
            else
                cout << r2 << " " << c2 << "\n";
        }
    }
}

void slv3() {
    cerr << "slv3\n";
    for (int i = 0; i < q; i++) {
        auto [r1, c1, r2, c2] = Q[i];
        int d1 = r1 - c1, d2 = r2 - c2;
        if (d1 <= K && d2 <= K) {
            if (d1 < d2) {
                cout << d1 << " " << 0 << "\n";
            } else if (d2 < d1){
                cout << d2 << " " << 0 << "\n";
            } else {
                if (r1 < r2)
                    cout << r1 << " " << c1 << "\n";
                else
                    cout << r2 << " " << c2 << "\n";
            }
        } else if (d1 < K && d2 > K) {
            cout << d1 << " " << 0 << "\n";
        } else if (d2 < K && d1 > K) {
            cout << d2 << " " << 0 << "\n";
        } else {
            if (c1 == c2) {
                if (r1 < r2) {
                    cout << r1 << " " << c1 << "\n";
                } else {
                    cout << r2 << " " << c2 << "\n";
                }
            } else if (c1 < c2) {
                cout << K << " " << c1 << "\n";
            } else {
                cout << K << " " << c2 << "\n";
            }
        }
    }
}

void solve(){

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a = rnd() % (n + 1), c = rnd() % (n + 1);
        b = rnd() % (a + 1), d = rnd() % (b + 1);
        Q.push_back({a, b, c, d});
        cerr << "q: " << a << " " << b <<  " " << c << " " << d << "\n";
    }
    int ok1 = 1;
    for (int i = 0; i < n; i++) {
        ok1 &= a[i] == i + 1;
    }
    if (ok1) {
        slv2();
        return;
    }
    int ok2 = 1;
    int was = 0;
    K = n;
    for (int i = 0; i < n; i++) {
        if (was) {
            ok2 &= a[i] == n - i + K;
        }
        else {
            if (a[i] == i + 1) {
                continue;
            }
            if (a[i] == n) {
                was = 1;
                K = i;
            } else {
                ok2 = 0;
            }
        }
    }
    if (ok2) {
        slv1();
        cerr << "\n";
        slv3();
        return;
    }
    if (n <= 3000 && q <= 3000) {
        slv1();
        return;
    }
}

signed main(){
    int t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << "\n";
}
