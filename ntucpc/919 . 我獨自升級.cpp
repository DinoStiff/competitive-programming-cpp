#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e3;
const int N = 2e5+7;

int main(){
    minji;
    ll n, m, c;
    cin>>n>>m>>c;
    vector<ll> v;
    ll l=INF, r=INF;
    for(ll i=0;i<n;i++){  
        ll x;
        cin>>x;
        v.push_back(x);
        l = min(l, i);
    }
    while(l+1<r){
        ll mid = (l+r)/2, cnt = 0;
        for(auto i:v){
            if(i<=mid){
                if((mid-i)%c==0){
                    cnt += (mid-i)/c;
                }
                else{
                    cnt += (mid-i)/c+1;
                }
            }
        }
        cout<<cnt<<' '<<l<<' '<<r<<'\n';
        if(cnt<=m)
            l=mid;
        else
            r = mid;
    }
    ll ans=INF;
    l=(l+r)/2;
    for(auto i:v){
        if(i<=l){
            if((l-i)%c==0){
                ans = min(ans, l);
            }
            else{
                ans = min(ans, i+c*(l-i)/c+1);
            }
        }
        cout<<ans<<' ';
    }
    cout<<ans<<'\n';
}