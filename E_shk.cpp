#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){
    
    int n, m;
    cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int one = 1;
    for (int i = 0; i < n; i++) one &= a[i] == 1;
    if (one) {
        cout << 1 << endl;
        return 1;
    }

    cerr << "next\n";

    int num = 0;
    while (1){
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += int(pow(a[i], num));
        }
        if (sum < m) num++, m -= sum;
        else break;
    }

    cerr << num << endl;

    for (int i = 0; i < n; i++) {
        if (int(powl(a[i], num)) >= m) {
            cout << a[i] << endl;
            return 1;
        } else {
            m -= powl(a[i], num);
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