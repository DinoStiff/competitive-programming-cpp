#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18, mod = 998244353;
const int N = 2e5+7;

ll mm(ll a, ll b) {
  return a * b % mod;
}

void amm(ll &a, ll b){
  a = mm(a, b);
}

ll Pow(ll x, ll k) {
  ll ans = 1;
  while (k) {
    if (k & 1)
      amm(ans, x);
    amm(x, x);
    k >>= 1;
  }
  return ans % mod;
}

int main(){
    minji;
    ll n, p, q, ans = 0;
    cin>>n>>p>>q;
    ll rm = Pow(q, mod-2);
}