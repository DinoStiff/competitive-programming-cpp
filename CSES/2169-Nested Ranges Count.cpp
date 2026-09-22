#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define f first
#define s second
 
map<ll, ll> m;
const ll N = 2e5 + 1;
ll bit[N + 1] = {0}, cnt;
void update(ll x, ll val) {
  for (; x <= cnt; x += x & -x)
    bit[x] += val;
}
ll query(ll x) {
  ll ans = 0;
  for (; x > 0; x -= x & -x)
    ans += bit[x];
  return ans;
}
 
bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
  if (a.f.f == b.f.f)
    return a.f.s > b.f.s;
  return a.f.f < b.f.f;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  ll n;
  cin >> n;
  set<ll> b;
  vector<pair<pair<ll, ll>, ll>> v(n);
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    v[i].s = i;
    v[i].f = {x, y};
    b.insert(y);
  }
  for (auto i : b) {
    m[i] = ++cnt;
  }
  sort(v.begin(), v.end(), cmp);
  update(m[v[n - 1].f.s], 1);
  ll ans[n];
  memset(ans, 0, sizeof ans);
  for (ll i = n - 2; i >= 0; i--) {
    ans[v[i].s] += query(m[v[i].f.s]);
    update(m[v[i].f.s], 1);
  }
 
  for (ll i = 0; i < n; i++)
    cout << ans[i] << ' ';
 
  memset(ans, 0, sizeof ans);
  memset(bit, 0, sizeof bit);
  update(1, 1);
  update(m[v[0].f.s] + 1, -1);
  for (ll i = 1; i < n; i++) {
    ans[v[i].s] += query(m[v[i].f.s]);
    update(1, 1);
    update(m[v[i].f.s] + 1, -1);
  }
  cout << '\n';
  for (ll i = 0; i < n; i++)
    cout << ans[i] << ' ';
}
