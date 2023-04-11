#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

const int mod = 1e9 + 9;
const int K = 31;
const int maxn = 2e5 + 5;
int p[maxn], inv[maxn];

int binpow(int n, int p){
    if (p == 0) {
        return 1;
    }
    int ans = binpow(n, p / 2);
    ans = ans * ans % mod;
    if (p & 1) {
        ans = ans * n % mod;
    }
    return ans;
}

int solve(){

    p[0] = 1;
    inv[0] = 1;
    int inv_K = binpow(K, mod - 2);
    for (int i = 1; i < maxn; i++) {
        p[i] = p[i - 1] * K % mod;
    }
    for (int i = 1; i < maxn; i++) {
        inv[i] = inv[i - 1] * inv_K % mod;
    }
    
    string s;
    cin>>s;
    int n = s.size();
    std::vector<std::vector<int>> h(n + 1);

    vector<pair<int, string>> Q;
    int q;
    cin >> q;
    while (q--) {
        int k;
        string t;
        cin >> t;
        Q.push_back({k, t});
        if (h[(int)t.size()].size() == 0) {

            h[(int)t.size()].resize(n + 1 - (int)t.size());            
            int hash = 0;
            for (int i = 0; i < (int)t.size(); i++) {
                hash = (hash + p[i] * (s[i] - 'a')) % mod;
            }
            h[t.size()][0] =  hash;
            for (int i = 0; i < n - (int)t.size(); i++) {
                hash = (hash + p[(int)t.size()] * s[i + (int)t.size()] - (s[i] - 'a') + mod) 
                        % mod * inv[0] % mod;
                h[(int)t.size()][i + 1] = hash;
            }
        }
    }

    return 1;

}
/*

..............

*/

signed main(){
    int t=1e9;
    // cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}