#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, s=3e5+1;
  cin >> n >> m;
  vector<int> x(n), seg(2*s);
  for (int& a:x) cin >> a;
  for (int a:x){
    int u = 0;
    for (int l(max(s+a-m,s)),r(min(s+a+m+1,s+s));l < r;l>>=1,r>>=1){
      if (l&1)
        u = max(u,seg[l++]);
      if (r&1)
        u = max(u,seg[--r]);
    }
    seg[s+a] = u+1;
    for (int i((s+a)>>1);i;i>>=1)
        seg[i] = max(seg[i<<1],seg[i<<1|1]);
  }
  cout << seg[1] << endl;
}