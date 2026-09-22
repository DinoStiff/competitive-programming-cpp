#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

void solve(){
    int n;
    cin>>n;
    ll pre[n+1];
    ll sum=0, ans=INF;
    pre[0]=0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        pre[i+1]=pre[i]+x;
        sum+=x;
    }
    for(int i=0;i<=n/2-1;i++){
        ans=min(ans, pre[i+n/2+1]-pre[i]);
    }
    cout<<ans<<' '<<sum-ans<<'\n';
}

int main(){
    minji;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}