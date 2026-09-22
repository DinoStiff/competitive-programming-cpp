#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int fp(int k){
  if(p[k] == k)
    return k;
  return p[k] = fp(p[k]);
}

bool same(int a, int b){
  return fp(a)==fp(b);
}

void merge(int a, int b){
  a = fp(a);
  b = fp(b);
  if(amt[a]<amt[b])
    swap(a, b);
  amt[a]+=amt[b];
  p[b] = a;
}

int main(){
    star;
    int n;
    cin>>n;
    
}