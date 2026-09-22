#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 3e3+7;

ll a[N], dp[N][N];

int main(){
    star;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n]<<'\n';
}