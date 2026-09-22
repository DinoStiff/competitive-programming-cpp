#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17, mod = 1e9+7;
const int N = 3e3+7;

ll dp[N][N], pre[N];

int main(){
    star;
    int n, l;
    string s;
    cin>>n>>s;
    dp[1][1]=1;
    pre[1] = 1;
    for(int i=2;i<=n;i++){
        if(s[i-2]=='<'){
            for(int j = 1;j<=i;j++){
                dp[i][j] = pre[j-1];
            }
        }
        else{
            for(int j = 1;j<=i;j++){
                dp[i][j] = (pre[i-1] - pre[j-1]+mod)%mod;
            }
        }
        for(int j = 1;j<=i;j++){
            pre[j] = (pre[j-1] + dp[i][j])%mod;
        }
    }
    cout<<pre[n]<<'\n';
}