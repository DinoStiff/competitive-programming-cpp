#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll mod = 1e9+7;
const int N = 1007;

ll dp[N][N];
char c[N][N];

int main(){
    nice;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    if(c[1][1]=='.')
        dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]=='.'&&!(i==1&&j==1))
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n][n]<<'\n';
}