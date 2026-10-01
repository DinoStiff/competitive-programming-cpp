#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
const ll mod = 998244353;

void solve(){
    int n, k;
    cin>>n>>k;
    ll ans = 1, cnt=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a==0)
            cnt++;
    }
    
    cout<<ans<<'\n';
}

int main(){
    minji;
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}