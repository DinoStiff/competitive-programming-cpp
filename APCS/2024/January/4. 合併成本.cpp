#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 4e2+7;

ll dp[N][N], pre[N];

int main(){
    star;
    int n, a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        pre[i]=pre[i-1]+a;
    }
    for(int len = 2;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r = l + len - 1;
            dp[l][r] = INF;
            for(int i=l;i<=r;i++){
                dp[l][r] = min(dp[l][r], dp[l][i]+dp[i+1][r] + abs(pre[r] - pre[i] - pre[i] + pre[l-1]));
            }
        }
    }
    cout<<dp[1][n]<<'\n';
}