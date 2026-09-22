#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int a, b, dp[505][505];

int main(){
    minji;
    cin >> a >> b;
    if (a < b) swap(a, b);
    memset(dp, 0x3F, sizeof(dp));
    for (int i = 0; i <= a; i++){
        dp[i][i] = 0;
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            for (int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1); 
            }
            for (int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout << dp[a][b];
}
