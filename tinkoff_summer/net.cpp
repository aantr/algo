#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define int ll

#ifdef ON_PC
void deb(string x){cout<<"x = "<<x<<endl;}
void deb(int x){cout<<"x = "<<x<<endl;}
void deb(vector<int> x){cout<<"x = ";for (auto i : x)cout<<i<<" ";cout<<endl;}
#else
#define deb(x)
#endif

int inf = 1e9;

int f(vector<vector<int>> &a){
    int ans = 0;
    for (int i=0;i<(int)a.size() - 2;i++){

        for (int j = 0;j<(int)a[0].size() - 2;j++){
            set<int> s1 = {a[i][j], a[i + 2][j], a[i][j + 2], a[i + 2][j + 2], a[i + 1][j], a[i][j + 1], a[i + 2][j+1], a[i+1][j+2]}, 
                    s2 = {a[i + 1][j], a[i][j + 1], a[i+1][j+1], a[i + 2][j+1], a[i+1][j+2]};
                if (s2.size() != 5){
                    ans += 1;
                }
        }
    }
    return ans;
}

int check(vector<vector<int>> &a){
    for (int i=0;i<(int)a.size() - 2;i++){
        for (int j = 0;j<(int)a[0].size() - 2;j++){
            set<int> s1 = {a[i][j], a[i + 2][j], a[i][j + 2], a[i + 2][j + 2], a[i + 1][j], a[i][j + 1], a[i + 2][j+1], a[i+1][j+2]}, 
                    s2 = {a[i + 1][j], a[i][j + 1], a[i+1][j+1], a[i + 2][j+1], a[i+1][j+2]};
                if (s2.size() != 5){
                    return 0;
                }
        }
    }
    return 1;
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rnd(123);

void solve() {

    int n, m;
    cin>>n>>m;
    int sw = n > m;
    if (sw)swap(n, m);
    vector<vector<int>> a(max(n, 3ll), std::vector<int> (max(m, 3ll)));
    a[0][1] = 1;
    a[1][0] = 2;
    a[1][2] = 3;
    a[2][1] = 4;
    a[1][1] = 5;

    a[0][0] = 1;
    a[2][0] = 2;
    a[0][2] = 2;
    a[2][2] = 1;

    a[0][0] = 3;
    a[2][0] = 1;
    a[0][2] = 4;
    a[2][2] = 2;

    for (int i=0;i<max(1ll, n - 2);i++){
        for (int j = 0;j<max(1ll, m - 2);j++){
            if(i+j==0)continue;
            int s = 1 + 2 + 3 + 4 + 5;
            s -= a[i + 1][j] + a[i][j+1] + a[i + 1][j+1] + a[i + 1][j+2] + a[i + 2][j+1];
            if (a[i + 1][j + 2] == 0) a[i + 1][j + 2] = s;
            else if (a[i + 2][j + 1] == 0) a[i + 2][j + 1] = s;
            if (!a[i][j]) a[i][j] = a[i + 1][j + 2];
            if (!a[i][j + 2])a[i][j + 2] = a[i + 2][j + 1];
            if (!a[i + 2][j + 2])a[i + 2][j + 2] = a[i + 1][j];
            if (!a[i + 2][j])a[i + 2][j] = a[i + 1][j + 2];
        }
    }

    if (n >= 5){
        vector<array<int, 2>> idx = {{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}};
        for (int i = 0;i<(int)pow(5, idx.size());i++){
            // vector<array<int, 2>> idx = {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {3, 2}, {3, 1}, {3, 0}};
            int v = i;
            for (int i=0;i<idx.size();i++){
                a[idx[i][0]][idx[i][1]] = v % 5 + 1;
                v/=5;
            }
            if (check(a)){
                // cout<<"ok\n";
                break;
            }
        }
    }

    if (sw){
        swap(n, m);
        vector<vector<int>> temp(n, vector<int>(m));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                temp[i][j] = a[j][i];
            }
        }
        a = temp;
    }

    int cur = f(a);
    ld temp=1;

    for (int i=0;i<30;i++){
        temp=1;
        int iter=2000;
        for (int i=0;i<iter;i++){
            temp*=0.995;
            auto y = a;
            int R = rnd()%n, C = rnd()%m;
            y[R][C] = rnd()%5+1;
            int fx = cur, fy=f(y);
            ld v = exp( (ld)(fx-fy) /temp );
            if (fy < fx){
                a=y;
                cur = fy;
            }else if (v > 0.5) {
                a = y;
                cur=fy;
            }
        }
    }
    
    deb(temp*100000);
    deb(f(a));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<a[i][j]<< " ";
        }
        cout<<"\n";
    }

}

signed main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cerr<<"--------\n";
    }
}