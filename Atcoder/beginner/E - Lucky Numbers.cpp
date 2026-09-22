#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const ll INF = 1e18;
const int N = 2e5+7;

ll n, m, s[100005], x[20], a[100005], b[100005], ans;
map<ll, ll> mp;

int main(){
	minji;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    for(int i=2;i<=n;i++){
        b[i]=s[i-1]-b[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mp[(b[i]-x[j])*(i%2?-1:1)]++; 
        }
    }
    for(auto [i, j]:mp){
        ans = max(ans, j);
    }
    cout<<ans<<'\n';
    return 0;
}