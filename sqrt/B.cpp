#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int A, B, d;

int get(int x){
  return min((x % d + d) % d, d - (x % d + d) % d);
}

signed main(){
  cin>>A>>B>>d;
  if (B < A) swap(A, B);
  assert(A != B);
  int p1 = floor(((long double) A + B) / 2);
  int p2 = p1 + 1;
  
  if ((B - A) % 2 == 0){
    cout<<p1<<" "<<get(p1)<<"\n";
  }else{
    int v = p1, v1 = p2;
    if (get(v1) < get(v)) swap(v, v1);
    cout<<v<<" "<<get(v)<<"\n";
  }
}
