#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;


ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	ll d = exgcd(b, a%b, x, y);
	ll t=x;
	x=y, y = t - a/b*y;
	return d;
}

int main(){
	ll T;
	cin>>T;
	while(T--){
		ll x, y, p, q;
        cin>>x>>y>>p>>q;
		ll ans=2e18, a, b;
		ll d=exgcd(2*(x+y),p+q,a,b);
		for(ll i=x;i<x+y;i++)
			for(ll j=p;j<p+q;j++)
				if((j-i)%d == 0){
					ll k=a*(j-i)/d,t=(p+q)/d;
					k=(k%t+t)%t;
					ans=min(ans,k*2*(x+y)+i);
				}
		if(ans==2e18)
            cout<<"infinity\n";
		else
            cout<<ans<<'\n';
	}
	return 0;
}