#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll a, b, c, d;

ll exgcd(int a, int b, ll &x, ll &y){
	if(!b){
		x=1;
        y=0;
		return a;
	}
	ll tmp = exgcd(b, a%b, y, x);
	y -= a/b * x;
	return tmp;
}

int main(){
    minji;
    ll x, y;
    cin>>a>>b>>c;
	c=-c;
	d = exgcd(a, b, x, y);
	if(c%d){
		cout<<"-1\n";
		return 0;
	}
	x *=c/d;
	y *=c/d;
	cout<<x<<' '<<y<<'\n';
	return 0;
}
