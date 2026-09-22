#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

ll Pow(ll x, ll k, ll mod){
    ll ans=1;
    while(k){
        if(k&1)
            ans = ans*x % mod;
        x = x*x %mod;
        k>>=1;
    }
    return ans;
}

int main(){
    star;
    ll n;
    cin>>n;
    while(n--){
        ll mod, a, b, x1, y1, x2, y2;
        cin>>mod>>a>>b>>x1>>y1>>x2>>y2;
        ll m = ((y2-y1)*Pow(x2-x1, mod-2, mod))%mod;
        m = (m+mod)%mod;
        ll x3 = (m*m - x1 - x2+2*mod)%mod, k = (y1 - m*x1)%mod;
        k = (k+mod)%mod;
        ll y3 = (m*x3+k)%mod;
        cout<<x3<<' '<<y3<<'\n';
    }
}
