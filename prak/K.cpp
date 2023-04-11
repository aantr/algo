#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC
#define x first
#define y second

const int maxn = 1e6 + 5;

int logn = 21;
std::vector<array<int, 4>> gr[maxn];
vector<int> jump[maxn];
int h[maxn];
int ans[maxn];
vector<array<int, 4>> queries[maxn]; // q, col, len, +-

int lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    for (int i = logn - 1; i >= 0; i--) {
        if (h[jump[a][i]] >= h[b]) {
            a = jump[a][i];
        }
    }
    // cout << a << " " << b << endl;
    if (a == b) return a;
    for (int i = logn - 1; i >= 0; i--) {
        if (jump[a][i] != jump[b][i]) {
            a = jump[a][i];
            b = jump[b][i];
        }
    }
    return jump[a][0];
}

void dfs_lca(int v, int p = -1) {
    if (p == -1) {
        jump[v][0] = v;
        h[v] = 0;
    } else{
        jump[v][0] = p;
        h[v] = h[p] + 1;
    }
    for (int i = 1; i < logn; i++) {
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
    }
    for (auto i : gr[v]) {
        if (i[0] == p) continue;
        dfs_lca(i[0], v);
    }
}

unordered_map<int, int> sum_col;
unordered_map<int, int> cnt_col;
int dist = 0;
void dfs(int v, int p = -1) {
    for (auto i : queries[v]) {
        ans[i[0]] += i[3] * (dist + cnt_col[i[1]] 
            * i[2] - sum_col[i[1]]);
    }
    for (auto i : gr[v]) {
        if (i[0] == p) continue;
        sum_col[i[2]] += i[1];
        cnt_col[i[2]]++;
        dist += i[1];
        dfs(i[0], v);
        dist -= i[1];
        cnt_col[i[2]]--;
        sum_col[i[2]] -= i[1];
    }
}

int solve(){
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        gr[a].push_back({b, d, c});
        gr[b].push_back({a, d, c});
    }
    for (int i = 0; i < maxn; i++) {
        jump[i].resize(logn);
    }
    dfs_lca(0);
    for (int i = 0; i < q; i++) {
        int x, y, v, u;
        cin >> x >> y >> v >> u;
        v--;
        u--;
        queries[u].push_back({i, x, y, +1});
        queries[v].push_back({i, x, y, +1});
        queries[lca(u, v)].push_back({i, x, y, -2});
        // cout << lca(u, v) << "\n";
    }

    dfs(0);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll t = 1e9;
    // cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}