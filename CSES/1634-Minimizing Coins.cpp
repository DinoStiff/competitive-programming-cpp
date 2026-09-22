#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9;
const int N = 1e6+7;

int n, x, a[105], dp[N];
  
int main() {
    star;
    for(int i=0;i<N;i++){
        dp[i]=INF;
    }
    dp[0] = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = 0; j+a[i] <= x; j++){
            dp[j+a[i]] = min(dp[j+a[i]], dp[j]+1);
            //cout<<dp[j]<<' '<<dp[j+a[i]]<<'\n';
        }
        //cout<<'\n';
    }
    if (dp[x] > x) cout << -1 << "\n";
    else cout << dp[x] << "\n";
}