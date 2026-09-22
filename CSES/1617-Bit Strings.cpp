#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17, mod = 1e9+7;
const int N = 2e5+7;

ll Pow(ll x, ll k){
    ll ans = 1;
    while(k>0){
        if(k&1)
            ans=ans*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return ans;
}

int main(){
    star;
    ll n;
    cin>>n;
    cout<<Pow(2, n)%mod;
}