#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 2e9+3;
const int N = 2e5+7;

int n, k;
vector<ll> a, b;

bool ok(ll m){
    ll sum=0;
    for(auto i:a){
        sum+=upper_bound(b.begin(), b.end(), m-i)-b.begin();
    }
    return sum>=k;
}

int main(){
    star;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());

    ll l=1, r=INF;
    while(l<r){
        ll m =(l+r)/2;
        if(ok(m))
            r = m;
        else
            l = m+1;
    }
    cout<<l<<'\n';
}