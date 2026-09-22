#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
ll dp[N];
int main(){
    star;
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        ll w, v;
        cin >> w >> v;

        for (int j = m; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

cout << dp[m] << endl;
}