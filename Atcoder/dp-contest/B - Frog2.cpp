#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9;
const int N = 2e5+7;

int h[N], dp[N];

int main(){
    star;
    int n, k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        dp[i]=INF;
    }
    dp[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=max(i-k, 1);j<i;j++){
            dp[i]=min(abs(h[i]-h[j])+dp[j], dp[i]);
        }
    }
  cout<<dp[n]<<endl;
}