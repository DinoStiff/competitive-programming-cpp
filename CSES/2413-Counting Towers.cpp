#include <bits/stdc++.h>
using namespace std;
  
int t, n, mod = 1e9+7;
long long dp[1000005][3];
  
int main(){
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= 1000000; i++){
        dp[i][1] = dp[i-1][1]*2 + dp[i-1][2];
        dp[i][1] %= mod;
        dp[i][2] = dp[i-1][1] + dp[i-1][2]*4;
        dp[i][2] %= mod;
    }
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        cout << (dp[n][1]+dp[n][2])%mod << "\n";
    }
}