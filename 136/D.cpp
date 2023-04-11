#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

std::vector<std::vector<int>> gr;
vector<int> used;
vector<int> dist;
int ans = 0;

void dfs(int v, int K, int p = -1) {
    used[v] = 1;
    dist[v] = 0;
    for (int i : gr[v]) {
        if (!used[i]) {
            dfs(i, K, v);
            if (dist[i] + 1>= K && p != -1) {
                ans ++;
            } else {
                dist[v] = max(dist[v], dist[i] + 1);
            }
        }
    }
    // cout << K << " " << v << " " << dist[v] << endl;
}

int solve(){    

    int n, k;
    cin >> n >> k;
    gr.assign(n, {});
    dist.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin>>x;
        x--;
        gr[x].push_back(i + 1);
        gr[i + 1].push_back(x);
    }

    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = l + r >> 1;
        used.assign(n, 0);
        ans = 0;
        dfs(0, m);
        // cout << m << " " << ans << "\n";
        if (ans <= k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
    return 0;

}

signed main(){

    int t = 1e9;
    cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}