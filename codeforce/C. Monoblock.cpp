#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
long long a[N];

int main(){
    minji;
    long long n, m;
    cin >> n >> m;
    long long tmp, x, ans = n * (n + 1) / 2;
    for (int i = 1; i <= n + m; i++) {
        if (i <= n) {
            cin >> x;
            tmp = i;
        } else {
            cin >> tmp >> x;
        }
        if (a[tmp] == a[tmp - 1])
            ans += (tmp - 1) * (n - tmp + 1);
        if (a[tmp] == a[tmp + 1])
            ans += tmp * (n - tmp);
        if (x == a[tmp - 1])
            ans -= (tmp - 1) * (n - tmp + 1);
        if (x == a[tmp + 1])
            ans -= tmp * (n - tmp);
        a[tmp] = x;
        if (i > n) cout << ans << '\n';
    }
    return 0;
}