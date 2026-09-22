#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e9;
const int N = 1e5;
ll w, h, n;

bool ok(ll k){
    return (k/w)*(k/h)>=n;
}

int main(){
    star;
    cin>>w>>h>>n;
    ll l=1, r=INF;
    if(max(w*n, h*n)>INF)
        r*=N;
    while(l<r){
        ll k = (l+r)/2;
        if(ok(k))
            r = k;
        else
            l = k+1;
    }
    cout<<l<<'\n';
}