#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e3+7;
const ll mod = 1e9+7;

ll dp[N][N];

int main(){
    star;
    int n, m;
    char c;
    cin>>n>>m;
    dp[1][0]=1LL;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            if(c == '.')
                dp[i][j]=dp[i-1][j]%mod+dp[i][j-1]%mod;
            else
                dp[i][j] = 0;
        }
    }
    cout<<dp[n][m]%mod<<'\n';
}