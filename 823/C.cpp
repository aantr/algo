#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){
    
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        ok &= s1[i] == s1[n-1-i] || s2[i] == s2[n-1-i];
    }
    
    cout << (ok ? "YES" : "NO") << "\n";

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