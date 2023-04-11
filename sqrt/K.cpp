// clang-format off
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double)clock() / CLOCKS_PER_SEC
// #define int ll

void solve() {
    const int K = 3000;
    const int maxn = 2e5 + 5;

    int n, q;
    cin >> n >> q;
    std::vector<int> a(maxn), b;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        temp.push_back(a[i]);
    }
    b = a;
    vector<array<int, 3>> Q, seg;
    vector<int> prev_q;
    vector<int> ans;
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            seg.push_back({x, y, i});
        } else {
            temp.push_back(y);
            Q.push_back({x, y, i});
            prev_q.push_back(b[x]);
            b[x] = y;
        }
    }
    ans.assign(q, -1);
    sort(temp.begin(), temp.end());

    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for (int i = 0; i < (int)a.size(); i++) {
        a[i] = (int)(lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin());
    }
    for (int i = 0; i < (int)Q.size(); i++) {
        Q[i][1] = (int)(lower_bound(temp.begin(), temp.end(), Q[i][1]) - temp.begin());
    }
    for (int i = 0; i < (int)prev_q.size(); i++) {
        prev_q[i] = (int)(lower_bound(temp.begin(), temp.end(), prev_q[i]) - temp.begin());
    }
    sort(seg.begin(), seg.end(), [&](array<int, 3> a, array<int, 3> b) { return make_tuple(a[0] / K, a[1] / K, a[2]) < make_tuple(b[0] / K, b[1] / K, b[2]); });

    int l = 0, r = 0, j = 0;
    vector<int> cnt(maxn);
    vector<int> cnt_cnt(maxn);
    vector<int> notin(maxn, 0);
    vector<int> notin_block(maxn, 0);
    notin[0] = 1;
    notin_block[0] = 1;

    function<void(int)> add = [&](int i) {
        cnt_cnt[cnt[i]]--;
        if (cnt[i] > 0 && cnt_cnt[cnt[i]] == 0) {
            notin[cnt[i]]--;
            notin_block[cnt[i] / K]--;
        }
        cnt[i]++;
        cnt_cnt[cnt[i]]++;
        if (cnt[i] > 0 && cnt_cnt[cnt[i]] == 1) {
            notin[cnt[i]]++;    
            notin_block[cnt[i] / K]++;
        }

    };

    function<void(int)> del = [&](int i) {
        cnt_cnt[cnt[i]]--;
        if (cnt[i] > 0 && cnt_cnt[cnt[i]] == 0) {
            notin[cnt[i]]--;
            notin_block[cnt[i] / K]--;
        }
        cnt[i]--;
        cnt_cnt[cnt[i]]++;
        if (cnt[i] > 0 && cnt_cnt[cnt[i]] == 1) {
            notin[cnt[i]]++;
            notin_block[cnt[i] / K]++;
        }
    };

    function<void(int)> add_change = [&](int i) {
        if (l <= Q[i][0] && Q[i][0] < r) {
            del(prev_q[i]);
            add(Q[i][1]);
        }
        a[Q[i][0]] = Q[i][1];
    };

    function<void(int)> del_change = [&](int i) {
        if (l <= Q[i][0] && Q[i][0] < r) {
            del(Q[i][1]);
            add(prev_q[i]);
        }
        a[Q[i][0]] = prev_q[i];
    };

    function<int()> get_ans = [&]() { 
        for (int i = 0; i <= n; i++) {
            if (notin_block[i] < K) {
                for (int j = max((int)1, i * K); j < i * K + K; j++) {
                    if (notin[j] == 0) {
                        return j;
                    }
                }
            }
        }

        return (int)0;

    };

    for (int i = 0; i < (int)seg.size(); i++) {
        auto [L, R, J] = seg[i];
        // cout<<L<<" "<<R<<" "<<J<<endl;
        while (l > L) {
            add(a[--l]);
        }
        while (r < R) {
            add(a[r++]);
        }
        while (l < L) {
            del(a[l++]);
        }
        while (r > R) {
            del(a[--r]);
        }
        while (j < (int)Q.size() && Q[j][2] < J) {
            add_change(j++);
        }
        while (j && Q[j - 1][2] > J) {
             del_change(--j);
        }
        ans[J] = get_ans();

    }

    for (int i = 0; i < q; i++) {
        if (~ans[i]) {
            cout << ans[i] << "\n";
        }
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    cerr << "Time: " << TIME << "\n";
}