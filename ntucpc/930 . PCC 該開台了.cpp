#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 507;

ll dp[N][N][2], v[N][N], b[N];

int main(){
    minji;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cin>>v[i][j];

        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int j=2;j<=m;j++){
        for(int i=0;i<n;i++){
            for(int k = 0;k<n;k++){
                if(k!=i){
                    for(int w=0;w<b[k];w++)
                        dp[i][j][0]=max(dp[i][j][0], dp[k][j-2][w]+v[i][j]);
                }
            }
            dp[i][j][0]=max(dp[i][j][0], dp[i][j-2][b[i]-1]+v[i][j]);
            for(int k=1;k<b[i];k++){
                dp[i][j][k]=dp[i][j-1][k-1]+v[i][j];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i];j++){
            ans = max(ans, dp[i][m][j]);
        }
    }
    cout<<ans<<'\n';
}