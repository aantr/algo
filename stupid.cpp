#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC
#define x first
#define y second

const int inf = 1e9;

int solve(){
    int n, k;
    cin >> n >> k;
    map<int, int> MN;
    std::vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        if (MN.find(a[i][0]) == MN.end()) {
            MN[a[i][0]] = a[i][1];
        } else {
            MN[a[i][0]] = min(MN[a[i][0]], a[i][1]);
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i][1] = MN[a[i][0]];
    }
    vector<int> mn(n);
    mn[0] = a[n - 1][1];
    for (int i = 1; i < n; i++) {
        mn[i] = min(mn[i - 1], a[n - 1 - i][1]);
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        a[i][0] -= tot;
        if (a[i][0] > 0 && i) {
            k -= mn[n - 1 - i];
        }
        while (a[i][0] > 0) {
            if (k < 0){
                cout << "NO\n";
                return 0;
            }
            tot += k;
            a[i][0] -= k;
            if (a[i][0] > 0) {
                k -= mn[n - 1 - i];
            }
        }
    }
    cout << "YES\n";
    return 0;
}

/*

(k * 2 - (m - 1) * R) * m / 2 >= a[i][0]


*/
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1e9;
    cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}