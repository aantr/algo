#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define TIME (double) clock() / CLOCKS_PER_SEC

// #define int ll

struct sparse {

    vector<vector<array<int, 2>>> t;
    sparse (vector<int> a) {
        int n = a.size();
        t.resize(21);
        t[0].assign(n, {});
        for (int i = 0; i < n; i++) {
            t[0][i] = {a[i], a[i]};
        }
        for (int i = 0; i < 20; i++) {
            t[i + 1].resize(n);
            for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
            // cout << 1 << " " << max(t[i][j][0], t[i][j + (1 << i)][0]) << endl;
                t[i + 1][j] = {max(t[i][j][0], t[i][j + (1 << i)][0]), 
                                min(t[i][j][1], t[i][j + (1 << i)][1])};
            }
        }

    }

    array<int, 2> get(int l, int r) {
        int lg = __lg(r - l);
        return {max(t[lg][l][0], t[lg][r - (1 << lg)][0]), 
                    min(t[lg][l][1], t[lg][r - (1 << lg)][1])};
    }

};

int solve(){

    int n, k;
    cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mn = 1e9;
    sparse S(a);
    for (int i = 0; i + k <= n; i++) {
        mn = min(mn, S.get(i, i + k)[0] - S.get(i, i + k)[1]);
    }
    cout << mn << "\n";
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