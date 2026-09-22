#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

vector<pii> v;

int main(){
    nice;
    int m, n, t, k, r;
    cin >> m >> n >> t >> k >> r;
    vector<pii> v;
    for (int i = 0; i < t; i++){
        int a;
        cin >> a;
        v.push_back({a, 1});
        v.push_back({a + k, -1});
    }
    v.push_back({n + 1, 0});
    sort(v.begin(), v.end());
    ll ans = 0;
    int cnt = 0, j=k, i=0;
    while(j <= n){
        while (v[i].first <= j)
            cnt += v[i++].second;
        int nxt = v[i].first;
        if (cnt & 1)
        {
            ans += (ll)(nxt - j) * (min(m + 1, r + k) - max(k, r));
        }
        j = nxt;
    }

    if (k & 1) ans = (ll)(n + 1 - k) * (m + 1 - k) - ans; 
    
    cout << ans << "\n";

}