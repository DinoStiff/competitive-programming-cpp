#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int n;
    cin>>n;
    ll ans = 0, a[n+2], sum[n+1], tmp = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[0]=0;
    tmp = -a[0];
    for(int i=1;i<=n;i++){
        sum[i] = sum [i-1] - a[i];
        ans+=abs(a[i]);
        a[i+1] += sum[i] + tmp;
    }
    cout<<ans<<'\n';
}