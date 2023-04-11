#include <bits/stdc++.h>
using namespace std;

vector<int> a;
const int LG = 20;

struct SparseTable {
    vector<vector<int>> t;
    SparseTable() {}
    SparseTable(vector<int> a) {
        t.resize(LG + 1);
        t[0] = a;
        for (int i = 1; i <= LG; i++) {
            t[i].resize(a.size());
            for (int j = 0; j + (1 << (i - 1)) < a.size(); j++) {
                t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int get(int l, int r) {
        if (l == r) {
            return INT_MAX;
        }
        int len = __lg(r - l);
        int ans = min(t[len][l], t[len][r - (1 << len)]);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> position(n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        position[a[i]] = i;
    }

    SparseTable sparse[2];
    for (int i = 0; i < 2; i++) {
        vector<int> b = a;
        for (int j = 0; j < n; j++) {
            if (j % 2 != i) {
                b[j] = INT_MAX;
            }
        }
        sparse[i] = SparseTable(b);
    }

    set<int> used = {-1, n};
    int MIN = INT_MAX;
    for (int i = 0; i < n; i += 2) {
        MIN = min(MIN, a[i]);
    }
    set<int> available = {MIN};
    vector<int> ans;
    for (int i = 0; i < n / 2; i++) {
        int v1 = *available.begin(), v2 = INT_MAX;
        int to = *used.upper_bound(position[v1]);
        v2 = sparse[(position[v1] + 1) % 2].get(position[v1] + 1, to);
        cout << v1 + 1 << " " << v2 + 1 << " ";
        cout.flush();
        available.erase(v1);
        available.erase(v2);

        if (position[v1] != position[v2] - 1) {
            int MIN = sparse[(position[v1] + 1) % 2].get(position[v1] + 1, position[v2]);
            available.insert(MIN);
        }
        int nxt = *used.upper_bound(position[v2]);
        int prv = *prev(used.lower_bound(position[v1]));
        if (prv + 1 != position[v1]) {
            int MIN = sparse[(prv + 1) % 2].get(prv + 1, position[v1]);
            available.insert(MIN);
        }

        if (position[v2] != nxt - 1) {
            int MIN = sparse[(position[v2] + 1) % 2].get(position[v2] + 1, nxt);
            available.insert(MIN);
        }

        used.insert(position[v1]);
        used.insert(position[v2]);
    }
}