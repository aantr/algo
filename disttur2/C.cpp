#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TIME (double) clock() / CLOCKS_PER_SEC

struct node{
	int l = 0, r = 0;
	int v = 0;
	node (){}
	node(int v): v(v) {

	}
};

node nodes[10000005];
int nodes_size = 1;

int create_node(int v){
	nodes[nodes_size] = node(v);
	return nodes_size++;
}

int add_next(int r, int v){
	int n = create_node(v);
	nodes[n].l=r;
	nodes[n].r = nodes[r].r;
	nodes[r].r = n;
	if (nodes[n].r){
		nodes[nodes[n].r].l = n;
	}
	return n;
}

int add_prev(int r, int v){
	int n = create_node(v);
	nodes[n].r=r;
	nodes[n].l = nodes[r].l;
	nodes[r].l = n;
	if (nodes[n].l){
		nodes[nodes[n].l].r = n;
	}
	return n;
}


int solve(){
	
	int left=0, right=0;
	int mid = 0; // [size / 2]
	int last_b = 0;
	int last_a = 0;
	bool where = 0; // left - 0, right - 1
	int sz = 0;

	int NNN;
	string s;
	cin >> NNN >> s;
	int cur = 1;
	string ans;
	for (int i = 0; i < NNN; i++){
		char c = s[i];
		if (c == 'a') {
			if (!left){
				left = create_node(cur++);
				right = left;
				mid = left;
				sz = 1;
				last_a = left;
				last_b = 0;
				where = 1;
			} else {
				if (!last_b){
					int n = add_next(last_a, cur++);
					last_a = n;
					right = n;
				} else {
					int n = add_prev(last_b, cur++);
					if (!last_a) left = n;
					last_a = n;
				}
				sz++;
				// upd mid;

				if (sz % 2 == 1 && where == 0) {
					if (mid == last_b) where = 1;
					mid = nodes[mid].l;
				}
				if (sz % 2 == 0 && where == 1){
					if (mid == last_a) where = 0;
					mid = nodes[mid].r;
				}
			}
		} else if (c == 'b') {
			if (!left){
				left = create_node(cur++);
				right = left;
				mid = left;
				sz = 1;
				last_b = left;
				last_a = 0;
				where = 0;
			} else {
				if (!last_b){
					int n = add_next(last_a, cur++);
					last_b = n;
					right = n;
				} else {
					int n = add_prev(last_b, cur++);
					if (!last_a) left = n;
					last_b = n;
				}
				sz++;
				// upd mid;
				if (sz % 2 == 1 && where == 0) {
					if (mid == last_b) where = 1;
					mid = nodes[mid].l;
				}
				if (sz % 2 == 0 && where == 1){
					if (mid == last_a) where = 0;
					mid = nodes[mid].r;
				}

			}
		} else if (c == 'A') {
			ans += (nodes[left].v % 10)+'0';
			if (left == last_a) last_a = 0;
			left = nodes[left].r;
			sz--;
			if (sz % 2 == 0) {
				if (mid == last_a) where = 0;
				mid = nodes[mid].r;
			}
			if (!left) {
				right = 0;
				last_b = 0;
				last_a = 0;
			} else {
				nodes[left].l = 0;
			}
		} else if (c == 'B'){
			sz--;
			if (sz % 2 == 1) {
				if (mid == last_b) where = 1;
				mid = nodes[mid].l;
			}
			ans += (nodes[right].v % 10)+'0';
			if (right == last_b) last_b = 0;
			right = nodes[right].l;
			
			if (right == 0) {
				left = 0;
				last_b = 0;
				last_a = 0;
			} else {
				nodes[right].r = 0;	
			}
		} else if (c == '>') {
			last_a = 0;
			last_b = left;
			where = 0;
		} else if (c == ']') {
			last_a = right;
			last_b = 0;
			where = 1;
		} else if (c == '<') {
			if (sz % 2 == 0) {
				last_b = mid;
				if (mid) last_a = nodes[mid].l;
				else last_a = 0;
			} else {
				last_b = mid;
				if (mid) last_a = nodes[mid].l;
				else last_a = 0;
			}
			where = 0;
		} else if (c == '[') {
			if (sz % 2 == 0) {
				last_b = mid;
				if (mid) last_a = nodes[mid].l;
				else last_a = 0;
				where = 0;
			} else {
				last_a = mid;
				if (mid) last_b = nodes[mid].r;
				else last_b = 0;
				where = 1;
			}
		}
	}

	cout << ans << "\n";

	return 0;

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin>>t;
	while (t--) {
		if (solve()) break;
	}
	cerr << "Time: " << TIME << endl;
}