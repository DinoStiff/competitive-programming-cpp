#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    ll n, m, x;
    cin >> n >> m >> x;
    vector<vector<vector<ll> > > dp(40, vector<vector<ll> >(n + 1, vector<ll>(n + 1, INF)));

    for(ll i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        dp[0][a][b] = min(dp[0][a][b], i);
    }

    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int w = 1; w <= n; w++) {
                    if(dp[i - 1][j][w] != INF && dp[i - 1][w][k] != INF) {
                        dp[i][j][k] = min(dp[i][j][k], max(dp[i - 1][j][w], dp[i - 1][w][k]));
                    }
                }
            }
        }
    }

    vector<vector<ll> > ans(n + 1, vector<ll>(n + 1, INF));
    for(int i = 1; i <= n; i++)
        ans[i][i] = -INF;

    for(int i = 0; i <= 30; i++) {
        vector<vector<ll> >tmp(n + 1, vector<ll>(n + 1, INF));
        if(x >> i & 1) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    for(int w = 1; w <= n; w++) {
                        if(ans[j][w] != INF && dp[i][w][k] != INF) {
                            tmp[j][k] = min(tmp[j][k], max(ans[j][w], dp[i][w][k]));
                        }
                    }
                }
            }
            ans = tmp;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << (ans[1][i] == INF ? -1 : ans[1][i]) << " ";
    }
    cout<<'\n';
    return 0;
}