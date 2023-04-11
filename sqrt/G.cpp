#include <bits/stdc++.h>
using namespace std;

const int K = 330;

int b[3][K][K];

int solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    function<void(int)> build = [&](int I) {
        int n = min((int)a.size() - I * K, K);
        for (int i = n - 1; i >= 0; i--) {
            if (i + b[0][I][i] >= n) {
                b[2][I][i] = i, b[1][I][i] = 1;
            } else {
                b[2][I][i] = b[2][I][i + b[0][I][i]], b[1][I][i] = b[1][I][i + b[0][I][i]] + 1;
            }
        }
    };

    for (int i = 0; i < n; i++) {
        b[0][i / K][i % K] = a[i];
        if (i % K == K - 1 || i == n - 1) {
            build(i / K);
        }
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            x--;
            int jumps = 0;
            while (x < n) {
                int B = x / K;
                int el = x % K;
                jumps += b[1][B][el];
                x = B * K + b[2][B][el];
                if (x + b[0][B][x % K] >= n) {
                    break;
                }
                x += b[0][B][x % K];
            }
            cout << x + 1 << " " << jumps << "\n";
        } else {
            int A, B;
            cin >> A >> B;
            A--;
            b[0][A / K][A % K] = B;
            build(A / K);
        }
    }

    return 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1e9;
    // cin>>t;
    while (t--) {
        if (solve())
            break;
    }
}