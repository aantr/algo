#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define TIME (double) clock() / CLOCKS_PER_SEC

#define int ll

const int maxn = 1e5 + 5;
std::vector<int> gr[maxn];
int used[maxn];
vector<int> res;
set<int> vert, vert1;
int h[maxn], d[maxn];

void dfs(int v, int p = -1) {
    used[v] = 1;
    res.push_back(v);
    d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
    int ch = 0;
    int ch2 = 0;
    int was = 0;
    for (int i : gr[v]) {
        int u = i;
        if (u != p) {
            if (!used[i]) {
                ch++;
                dfs(i, v);
                d[v] = min(d[v], d[u]);
                if (h[v] <= d[u] && p != -1) {
                    vert.insert(v);
                    was = 1;
                    ch2 ++;
                    if (gr[v].size() == 2) {
                        // vert1.insert(v);
                    }
                }
            } else {
                d[v] = min(d[v], h[i]);
            }
        }
    }
    if (p == -1 && ch > 1) {
        vert.insert(v);
        was = 1;
        if (ch == 2) {
            vert1.insert(v);
        }
    }
    // cout << v << " " << ch2 << "\n";
    if (was && p != -1 && ch2 == 1) {
        vert1.insert(v);
    }
}

int solve(){

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<array<int, 3>> comp;
    int c1 = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            res.clear();
            vert.clear();
            vert1.clear();
            dfs(i);
            if (res.size() > 1) {
                comp.push_back({(int)res.size() - (int)vert.size(), 
                        (int)vert1.size(), (int)res.size()});
                s += (int)res.size() - (int)vert.size();
            } else {
                c1++;
            }
        }
    }
    int ans = 0;
    int A = 0;
    for (auto i : comp) {
        ans += i[0] * (s - i[0]);
        A += i[1] * c1;
    }

    cout << ans / 2 + A << "\n";
    return 1;
}

signed main(){
    int t = 1e9;
    // cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}