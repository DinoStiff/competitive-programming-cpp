#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll a[N], d[N], l[N], r[N], n;

int main(){
    star;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i] = a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++){
       l[i] = d[i]<=0? l[i-1]-d[i]+1:l[i-1];
    }
    for(int i=n;i>=2;i--){
       r[i] = d[i]>=0? r[i+1]+d[i]+1:r[i+1];
    }
    ll ans = INF;
    for(int i=1;i<=n;i++){
        ans = min(ans, max(l[i], r[i+1]));
    }
    cout<<ans<<'\n';
}