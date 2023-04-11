#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

struct point{

	ld x=0, y=0;
	point() {}
	point(ld x, ld y) : x(x), y(y){

	}

	point operator-(point other){
		return point(x - other.x, y - other.y);
	}

	point operator+(point other){
		return point(x + other.x, y + other.y);
	}

	ld operator% (point other){
		return x * other.y - y * other.x;
	}

	ld cross(point a, point b){
		return (a - *this) % (b - *this);
	}

};

void solve(){
	
	int n;
	cin>>n;
	vector<point> a(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin>>x>>y;
		a[i] = point(x, y);
	}

	int mn = 0, mx = 0;
	for (int i = 0;i < n;i++){
		if (a[i].y < a[mn].y) mn = i;
		if (a[i].y > a[mx].y) mx = i;
	}

	int q;
	cin>>q;

	while (q --){
		int y;
		cin>>y;



	}

}

signed main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}