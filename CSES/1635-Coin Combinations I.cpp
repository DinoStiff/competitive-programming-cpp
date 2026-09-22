#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7, mod = 1e9+7;

int n, x, c[105], dp[1000005];
  
int main() {
    star;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    dp[0] = 1;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < n; j++){
            if (i+c[j] > x) continue;
            dp[i+c[j]] += dp[i];
            dp[i+c[j]] %= mod;
        }
    }
    cout << dp[x] << '\n';
}