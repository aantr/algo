#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int solve(){

    string s;
    cin>>s;
    int n = s.size();
    int cnt = 0;
    vector<set<int>> pos(26);
    for (int i=0;i<n;i++){
        pos[s[i]-'a'].insert(i);
    }
    for (int i=0;i<26;i++)cnt += pos[i].size() % 2;
    if (cnt > 1) {
        cout<<-1<<"\n";
        return 0;
    }
    for (int i=0;i<(n + 1)/2;i++){
        int mn = 1e9;
        int ch = 0;
        for (int j=0;j<26;j++){
            if (pos[j].size() < 2)continue;
            int val = *pos[j].begin();

        }
    }

    return 0;

}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // cin>>t;
    #ifndef ON_PC
    /*
    freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);
    */
    #endif
    while (t--){
        if (solve()) break;
    }
    cerr<<"time: "<<(double)clock() / (double)CLOCKS_PER_SEC<<"\n";
}