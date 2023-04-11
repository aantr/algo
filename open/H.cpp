#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC
#define all(x) x.begin(), x.end()

int solve(){

    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<array<int, 2>> queries;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        queries.push_back({l, r});
    }
    const int K = 300;
    sort(all(queries), [&] (array<int, 2> &a, array<int, 2> &b) {return a[0] / K < b[0] || a[0] == b[0] && a[1] < b[1];});

    int L = 0, R = 0;
    function<void(int)> addR() = [&] (int i) {

    };
    function<void(int)> addL() = [&] (int i) {

    };
    function<void(int)> delL() = [&] (int i) {

    };
    function<void()> clear() = [&] () {
        L = 0;
        R = 0;
    };

    for (int i = 0; i < m; i++) {
        if (i && queries[i][0] / K > queries[i - 1][0] / K) {
            clear();
        }

        while (R < queries[i][1]) {
            addR(R);
            R++;
        }
        while (L > queries[i][0]) {
            L--;
            addL(L);
        }
        while (L < queries[i][0]) {
            delL(L);
            L++;
        }
    }

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