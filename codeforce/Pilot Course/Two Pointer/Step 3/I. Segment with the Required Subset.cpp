#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17, mod = 1e9+7;
const int N = 1e5+7;
ll n, s, dp[1005], a[N];

void add(int k){
    for(int i=s;i>=k;i--){
        dp[i] += dp[i-k];
        dp[i]%=mod;
    }
}

void del(int k){
    for(int i=k;i<=s;i++){
        dp[i] = (dp[i]-dp[i-k]+mod)%mod;
    }
}

int main(){
    star;
    dp[0]=1;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int r=1, ans = N;
    for(int l=1;l<=n;l++){
        while(r<=n&&!dp[s]){
            add(a[r]);
            r++;
        }
        if(dp[s])
            ans = min(ans, r-l);
        del(a[l]);
    }
    if(ans>n)
        cout<<"-1\n";
    else
        cout<<ans<<'\n';
}