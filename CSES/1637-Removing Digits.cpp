#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int n, dp[1000005];
  
int main() {
    star;
    memset(dp, 0x3F, sizeof dp);
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        int tmp = i;
        while (tmp){
            dp[i] = min(dp[i], dp[i-(tmp%10)]+1);
            tmp /= 10;
        }
    }
    cout << dp[n] << '\n';
}