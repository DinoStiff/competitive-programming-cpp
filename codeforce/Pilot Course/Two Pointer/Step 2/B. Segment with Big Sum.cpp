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
    vector<ll> v;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    int r=0, ans=N; 
    ll sum=0;
    for(int l=0;l<n;l++){
        while(r<n&&sum<s){
            sum+=v[r];
            r++;
        }
        if(sum>=s)
            ans = min(ans, r-l);
        sum -= v[l];

    }
    if(ans==N)
        cout<<"-1\n";
    else
        cout<<ans<<'\n';
}