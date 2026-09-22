#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll Pow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = Pow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll solve(ll n) { 
    if(n == 0) return 0;

    vector<ll> v;
    ll tmp = n;
    while(tmp > 0){
        v.push_back(tmp % 10);
        tmp /= 10;
    }

    reverse(v.begin(), v.end());

    ll len = v.size(), ans = 0;
    for(int i = 1; i <= len - 1; i++){
        for(int j = 1; j <= 9; j++){
            ll x = j;
            ans += Pow(x, i - 1);
        }
    }
    for(ll i = 1; i < v[0]; i++){
        ll x = i;
        ans += Pow(x, len-1);
    }

    ll b = v[0];
    bool ok = true;
    for(int i = 1; i < len && ok; i++){
        ll x = min(v[i], b);
        ans +=  x * Pow(b, len - i - 1);
        if(v[i] >= b) ok = false;
    }

    if(ok) ans++;

    return ans;
}

int main() {
    minji;
    ll l, r;
    cin >> l >> r;
    ll ans = solve(r) - solve(l - 1);
    cout << ans << endl;
    return 0;
}
