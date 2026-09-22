#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    ll n, s;
    vector<ll> w, v;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        w.push_back(a);
    }
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    ll r=0, ans=0; 
    ll sum=0, val=0;
    for(int l=0;l<n;l++){
        while(r<n&&sum+w[r]<=s){
            sum+=w[r];
            val+=v[r];
            r++;
            ans = max(ans, val);
        }
        sum -= w[l];
        val -= v[l];
    }
    cout<<ans<<'\n';
}