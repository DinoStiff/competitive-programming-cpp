#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, a[5005];
ll dp[5005][5005], pre[5005];
  
ll f(int l, int r){
    if (dp[l][r] != -1) return dp[l][r];
    if (r-l <= 1) return dp[l][r] = max(a[l], a[r]);
    dp[l][r] = a[l] + pre[r] - pre[l] - f(l+1, r);
    dp[l][r] = max(dp[l][r], pre[r-1] - pre[l-1] - f(l, r-1) + a[r]);
    pre[l-1] + pre[n] - pre[r] - f(l, r-1);
    return dp[l][r];
}

int main(){
    minji;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
    }
    cout << f(1, n);
}