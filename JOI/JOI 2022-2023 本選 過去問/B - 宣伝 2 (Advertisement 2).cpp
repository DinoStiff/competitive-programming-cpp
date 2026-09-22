#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e9;
const int N = 2e5+7;

int main(){
    star;
    ll n; cin >> n;
	vector<pii> a(n);

	for(int i=0; i<n; i++) {
		ll x, y; 
        cin >> x >> y;
		a[i]={x-y,-x-y};
	}
	sort(all(a));
	int tmp=INF, ans=0;
	for(auto x:a){
		if(x.second<tmp){
			tmp=x.second;
			ans++;
		}
	}
	cout<<ans<<'\n';
}