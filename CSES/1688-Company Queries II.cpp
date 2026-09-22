#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int n, q, p[N][20];

int solve(int a, int b) {
  int x = dp(a), y = dp(b);
  if (x > y) {
    swap(a, b);
    swap(x, y);
  }
  y -= x;
  for (int i = 0; i < 20; i++) {
    if (y & (1 << i))
      b = p[b][i];
  }
  if (a == b)
    return a;
  for (int i = 19; i >= 0; i--) {
    if (p[a][i] != p[b][i]) {
      a = p[a][i];
      b = p[b][i];
    }
  }
  return p[a][0];

}

int main(){
    star;
    int n, q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>p[i][0];
    }
    for(int i=1;i<20;i++){
        for()
    }
}