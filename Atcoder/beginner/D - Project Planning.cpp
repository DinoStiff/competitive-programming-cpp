#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

vector<ll> v(N);

int n, k;

bool ok(ll x){
    ll cnt = x*k;
    for(auto i:v){
        cnt -= min(i, x);
    }
    return cnt<=0;
}

int main(){
    minji;

    cin>>n>>k;
    ll l=0, r=INF/k;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    while(l+1<r){
        ll mid = (l+r)/2;
        if(ok(mid))
            l = mid;
        else
            r = mid;
        
    }
    cout<<l<<'\n';
}