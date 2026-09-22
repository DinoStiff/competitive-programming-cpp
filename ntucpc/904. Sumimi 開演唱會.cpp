#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int arr[N], seg[N * 4];
 
void modify(int k, int val, int l, int r, int idx){
  if(l==r){
    seg[idx] = val;
    return;
  }
  
  int m = (l+r)/2;
 
  if(k<=m)
    modify(k, val, l, m, idx*2);
  else
    modify(k, val, m+1, r, idx*2+1);
  seg[idx] = max(seg[idx*2], seg[idx*2 + 1]);
}
 
int query(int ql, int qr, int l, int r, int idx) {
  if (ql <= l && r <= qr) {
    return seg[idx];
  }
 
  int m = (l + r) / 2;
  
  if (m >= qr)
    return query(ql, qr, l, m, idx * 2);
  
  if (m < ql)
    return query(ql, qr, m + 1, r, idx * 2 + 1);
  
  return max(query(ql, qr, l, m, idx * 2), query(ql, qr, m + 1, r, idx * 2 + 1));
 
  
}
int main(){
    minji;
    int n, x, y;
    cin>>n>>x>>y;
    ll ans=-INF;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=x;i++){
        
    }
}
