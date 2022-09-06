#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

struct point{
    ld x, y;
    point(ld x, ld y) : x(x), y(y){

    }

    point operator-(point p){
        return point(x-p.x ,y-p.y);
    }
    point operator+(point p){
        return point(x+p.x ,y+p.y);
    }
    ld cross(point p){
        return x * p.y - y * p.x;
    }
    ld cross(point a, point b){
        return (a - *this).cross(b - *this);
    }


};

int solve(){

    int n;
    cin>>n;
    vector<point> a1, a2;
    for (int i=0;i<n;i++){
        int x, y;
        point p(x, y);
        a1.push_back(p);
    }
    for (int i=0;i<n;i++){
        int x, y;
        point p(x, y);
        a2.push_back(p);
    }
    vector<int> h1, h2;
    for (int i=0;i<n;i++){
        h1.push_back((int) a1[i].cross(a1[(i - 1 + n) % n], a1[(i + 1) % n]));
    }
    for (int i=0;i<n;i++){
        h2.push_back((int) a2[i].cross(a2[(i - 1 + n) % n], a2[(i + 1) % n]));
    }

    
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1e9;
    // cin>>t;
    while (t--){
        if (solve())break;
    }
    cerr<<"time: "<<(double)clock() / (double)CLOCKS_PER_SEC<<"\n";
}