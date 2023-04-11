#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve() {
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int Prev = -1;
    set<array<int, 2>> ones;
    set<int> ones_idx;
    multiset<int> all_dist;
    std::vector<array<int, 2>> dist(n, {-1, -1});
    for (int i = 0; i < n; i++) {
        if (s[i] - '0') {
            all_dist.insert(i - Prev - 1);
            dist[i][0] = i - Prev - 1;
            if (Prev != -1) {
                dist[Prev][1] = i - Prev - 1;
            }
            ones_idx.insert(i);
            Prev = i;
        }
    }
    dist[Prev][1] = n - Prev - 1;
    all_dist.insert(n - Prev - 1);

    const int KK = 1e9, KK1 = 1;
    for (int i = 0; i < n; i++) {
        if (dist[i][0] != -1) {
            ones.insert({(int)KK * min(dist[i][0], dist[i][1]) + KK1 * (dist[i][0] + dist[i][1]), i});
        }
    }
    int ans = 0;
    int ONES = 0;
    while (ones.size()) {
        int mn_dist = *all_dist.begin();
        int v = ((int)ones.size() + 1) * mn_dist + (int) ones.size();
        if (v > ans) {
            ans = v;
            ONES = (int)ones.size();
        }
        auto first = ones.begin();
        cerr << (*first)[0] << " ";
        auto IDX = ones_idx.lower_bound((*first)[1]);
        cerr << *IDX << "\n";
        all_dist.erase(all_dist.find(dist[(*first)[1]][0]));
        all_dist.erase(all_dist.find(dist[(*first)[1]][1]));
        all_dist.insert(dist[(*first)[1]][0] + dist[(*first)[1]][1]);
        if (IDX != ones_idx.begin()) {
            int idx = (*prev(IDX));
            int i = idx;
            // cout << *IDX << " ";
            assert(idx < *IDX);
            ones.erase({(int)KK * min(dist[i][0], dist[i][1]) + KK1 * (dist[i][0] + dist[i][1]), idx});
            dist[idx][1] = dist[(*first)[1]][0] + dist[(*first)[1]][1];
            ones.insert({(int) KK * min(dist[i][0], dist[i][1]) + KK1 * (dist[i][0] + dist[i][1]), idx});
        }
        if (IDX != prev(ones_idx.end())) {
            int idx = (*next(IDX));
            int i = idx;
            // cout << *IDX << " ";
            assert(idx > *IDX);
            ones.erase({(int)KK * min(dist[i][0], dist[i][1]) + KK1 * (dist[i][0] + dist[i][1]), idx});
            dist[idx][0] = dist[(*first)[1]][0] + dist[(*first)[1]][1];
            ones.insert({(int)KK * min(dist[i][0], dist[i][1]) + KK1 * (dist[i][0] + dist[i][1]), idx});
        }
        ones.erase(first);
        ones_idx.erase(IDX);

    }

    cout << ans << "\n";
    int len = (ans - ONES) / (ONES + 1);
    for (int i = 0; i < ONES; i++)  {
        for (int j = 0; j < len; j++) {
            cout << '0';
        }
        cout << '1';
    }
    for (int j = 0; j < len; j++) {
        cout << '0';
    }
    return 1;
}

void precalc() {
}

signed main() {
    precalc();
    int t = 1e9;
    // cin >> t;
    // freopen("output.txt", "w", stdout);
    while (t--) {
        if (solve()) {
            break;
        }
    }
    cerr << "Time: " << TIME << endl;
}
