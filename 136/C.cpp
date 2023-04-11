#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

const int mod = 998244353;

int binpow(int x, int p) {
    if (p == 0) return 1;
    int ans = binpow(x, p / 2);
    ans = ans * ans % mod;
    if (p % 2 == 1) {
        ans = ans * x % mod;
    }
    return ans;
}
int fact[100];

int c(int n, int k) {
    return fact[n] * binpow(fact[n - k], mod - 2) % mod * binpow(fact[k], mod - 2) % mod;
}


int solve(){

    int n;
    cin >> n;
    std::vector<int> lose(n + 1), win(n + 1);
    lose[1] = 0;
    win[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        win[i] = (c(i * 2 - 1, i) + lose[i - 1]) % mod;
        lose[i] = (win[i - 1]) % mod;
        for (int j = 3; j <= i + 1; j ++) lose[i] = (lose[i] + c(i * 2 - j, i - 1)) % mod;

        //cout << win[i] << " " << lose[i] << "\n";
    }

    cout << win[n / 2] << " " << lose[n / 2] << " " << (c(n, n / 2) - win[n / 2] - lose[n / 2] + 2 * mod) % mod << "\n";

    return 0;

}

signed main(){

    fact[0] = 1;
    for (int i = 0; i < 100; i++) fact[i + 1] = fact[i] * (i + 1) % mod;

    int t = 1e9;
    cin>>t;
    while (t--) {
        if (solve()) break;
    }
    cerr<<"Time: "<<TIME<<endl;
}