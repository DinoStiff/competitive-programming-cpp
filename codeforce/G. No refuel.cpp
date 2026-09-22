#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define alcohol ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int p[N], amt[N];
vector<pair<int, int>> edge[N];

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

struct Edge{
  int a, b, w;
};

int main(){
  alcohol;
  int n, m, a, b, c, h=0, ans=0;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    p[i]=i;
    amt[i]=1;
  }
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    edge[c].push_back({a, b});
    h = max(c, h);
  }
  for(int i=0;i<=h;i++){
    for(auto [s, e]:edge[i]){
      if(!same(s, e)){
        merge(s, e);
        ans=max(ans, i);
      }
    }
  }
  cout<<ans<<'\n';
}