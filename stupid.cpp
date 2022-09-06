#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

//#define int ll

string makestr(int s, int n){
    string res;
    for (int i=0;i<n;i++){
        res+=(s&1)+'0';
        s>>=1;
    }
    return res;
}

void solve() {
    
    int n, m;
    cin>>n>>m;

    int l=n;
    vector<array<int, 3>> left, right, middle;
    for (int i=0;i<m;i++){
        int L, R, X;
        cin>>L>>R>>X;
        L--;
        left.push_back({L, R, X});
    }

    string ans;
    int sum=n;
    for (int i=0;i<n;i++){
        ans+="1 ";
    }

    for (int mask=0;mask<(1<<l);mask++){
        int ok=1;
        vector<int> p(l+1);
        for (int i=0;i<l;i++){
            p[i+1]=p[i]+(mask>>i&1);
            p[i+1]%=2;
        }
        for (auto check : left){
            ok &= (p[check[1]]+p[check[0]])%2==check[2];
        }
        if (ok){
            string s;
            int Sum=0;
            ll cur = mask;
            for (int i=0;i<n;i++){
                s+=(cur&1)+'0';
                Sum +=cur&1;
                cur>>=1;
                s+=' ';
            }
            if (Sum < sum || (Sum == sum && s < ans)){
                ans=s;
                sum=Sum;
            }
            
        }
        
    }

    cout<<ans<<endl;
   
}


signed main(){
    fast;
    int t=1;
    freopen("stupid.out", "w", stdout);
    #ifndef ON_PC
    /*freopen("hull.in", "r", stdin);
    freopen("hull.out", "w", stdout);*/
    #endif
    //cin>>t;
    while(t--){
        int time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        solve();
        cerr<<endl<<"[finished in "<< 
        clock()*1.0/CLOCKS_PER_SEC
         << " sec]\n--------\n"<<endl;
    }
}