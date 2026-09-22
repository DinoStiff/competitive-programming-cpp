#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e6+7;

ll cnt[N], tol[N];

int main(){
    star;
    ll n, l, r = 0, sum = 0;;
    cin >> n >> l;

    for (int i = 0; i < n;i++){
        ll a;
        cin >> a;
        sum += a;
        cnt[a + 1]++;
        tol[a + 1] += a;
        r = max(r, a);
    }

    for (ll i = 1; i <= r + 1;i++){
        cnt[i] += cnt[i - 1];
        tol[i] += tol[i - 1];
    }

    ll ans = 0, now, j;

    for (ll i = l; i <= r;i++){
        now = sum;
        for (j = 0; j < (r / i);j++){
            now -= (tol[j * i + i] - tol[j * i] - (i * j * (cnt[j * i + i] - cnt[j * i])));
        }
        now -= (tol[r + 1] - tol[j * i] - (i * j * (cnt[r + 1] - cnt[j * i])));
        ans = max(ans, now);
    }

    cout << ans << '\n';

}