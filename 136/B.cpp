#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){

    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = b[i-1]+a[i];
        if (a[i] && b[i-1]>=a[i]){
            cout << -1 << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) cout << b[i] << " "; cout << "\n";

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