#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9;
const int N = 2e5+7;
int dp[N], h[N];

int main(){
    star;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    for(int i=3;i<=n;i++){
        dp[i] = min(abs(h[i]-h[i-1])+dp[i-1], abs(h[i]-h[i-2])+dp[i-2]);
    }
    cout<<dp[n]<<'\n';
}