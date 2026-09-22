#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll dp[2005][2005];

// ll solve(ll x, ll y){
//     if(dp[x][y])
//         return dp[x][y];
//     if(x==y)
//         return dp[x][y]=1;
//     return dp[x][y] = solve ()
// }

int main(){
    minji;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
        }
    }
    ll ans =0;
    for(int i=3;i<=min(n, m);i++){
        ans+=(n-i+1)*(m-i+1);
    }
    cout<<ans<<'\n';
}