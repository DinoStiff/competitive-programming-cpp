#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 7e4+7, mod = 1e9+7;
int n, dp[505][N];
int main(){
    star;
    cin >> n;
    int sum = n * (n+1) / 2;
    if (sum % 2) {
        cout << 0;
        return 0;
    }
    sum /= 2;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= sum; j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            if (j >= i){
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= mod;
            }
        }
    }
    ll ans = dp[n][sum];
    ans *= 500000004;
    ans %= mod;
    cout << ans << "\n";
}