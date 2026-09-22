#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    ll k;
	cin>>k;
	ll ans=INF;
	for(ll x=0;x*x<=k;x++){
		ll y=sqrt(k-x*x);
		ans=min(ans,abs(k-x*x-y*y));
		y++;
		ans=min(ans,abs(k-x*x-y*y));
	}
	cout<<ans<<'\n';
}