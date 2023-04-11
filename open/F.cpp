#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

const int maxn = 2e5 + 5;

struct fenwick {

    vector<int> t;
    fenwick() {
        t.resize(maxn + 1);
    }

    void add(int l, int r, int v) {
        add(l, +v);
        add(r + 1, -v);
    }

    void add(int r, int v) {
        r++;
        for (int i = r; i < maxn + 1; i += i & -i) {
            t[i] += v;
        }
    }

    int get(int l, int r) {
        return get(r) - get(l);
    }

    int get(int i) {
        int ans = 0;
        for (;i > 0; i -= i & -i) {
            ans += t[i];
        }
        return ans;
    }

};

vector<int> gr1[maxn], gr2[maxn];
vector<int> euler;
int pref1[maxn];
fenwick pref;
vector<array<int, 2>> idx;

int ans = 0;

void dfs1(int v, int p = -1) {

    // ans += pref.get(0, idx[v][0] + 1);
    // pref.add(idx[v][0], idx[v][1] + 1, 1);
    ans += pref1[idx[v][0]];
    for (int i = idx[v][0] + 1; i <= idx[v][1] - 1; i++) {
        pref1[i]++;
    }

    for (int i : gr1[v]) {
        if (i != p) {
            dfs1(i, v);
        }
    }

    // pref.add(idx[v][0], idx[v][1] + 1, -1);
    for (int i = idx[v][0] + 1; i <= idx[v][1] - 1; i++) {
        pref1[i]++;
    }
      

}

void dfs2(int v, int p = -1) {
    euler.push_back(v);
    for (int i : gr2[v]) {
        if (i != p) {
            dfs2(i, v);
        }
    }
    euler.push_back(v);
}

int solve(){

    int n;
    cin >> n;
    int b1 = -1, b2 = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            b1 = i;
            continue;
        }
        gr1[i].push_back(x - 1);
        gr1[x - 1].push_back(i);

    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            b2 = i;
            continue;
        }
        gr2[i].push_back(x - 1);
        gr2[x - 1].push_back(i);

    }

    assert(b1 != -1 && b2 != -1);
    dfs2(b2);       
    idx.assign(n, array<int, 2>{-1, -1});

    for (int i = 0; i < n * 2; i++) {
        if (idx[euler[i]][0] == -1) {
            idx[euler[i]][0] = i;
        } else {
            idx[euler[i]][1] = i;
        }
    }

    dfs1(b1);

    cout << ans << "\n";
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