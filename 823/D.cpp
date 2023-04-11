#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define TIME (double) clock() / CLOCKS_PER_SEC

int solve(){
    
    string s;
    cin>>s;
    int n = s.size();
    vector<int> a;
    multiset<int> used;
    for (int i = 0; i < n; i++) {
        while (a.size() && a.back() > s[i]-'0'){
            used.insert(min(9ll, a.back() + 1));
            a.pop_back();
        }
        a.push_back(s[i]-'0');
    }
    for (int i : a) used.insert(i);
    for (int i : used) cout << i;
    cout << "\n";
    

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