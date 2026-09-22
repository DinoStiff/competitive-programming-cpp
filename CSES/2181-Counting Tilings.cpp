#include <bits/stdc++.h>
using namespace std;
  
int t, n, m, dp[1005][11][1<<11], mod = 1e9+7;
  
int main(){
    cin >> m >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][m][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < (1<<m); j++){
            dp[i][0][j<<1] = dp[i-1][m][j];
        }
        for (int j = 1; j <= m; j++){
            int x = (1<<(j-1));
            int y = (1<<j);
            for (int k = 0; k < (1<<(m+1)); k++){
                dp[i][j-1][k] %= mod;
                if ((k&x) && (k&y)) continue;
                if ((k&x)) dp[i][j][k^x] += dp[i][j-1][k];
                else if ((k&y)) dp[i][j][k^y] += dp[i][j-1][k];
                else{
                    dp[i][j][k^x] += dp[i][j-1][k];
                    dp[i][j][k^y] += dp[i][j-1][k];
                }
            }
        }
    }
    dp[n][m][0] %= mod;
    cout << dp[n][m][0] << "\n";
}