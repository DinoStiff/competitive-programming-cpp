#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

set<int> s[N]; 
int p[N]; 

ll square(ll x) {
    return x*x;
}

int Find(int idx) {
    return p[idx] == idx ? idx : p[idx] = Find(p[idx]);
}


ll len(int a, int b) {
	ll cnt=INF; 
	for(auto i:s[a]) {
		auto tmp = s[b].lower_bound(i); 
		if(tmp!=s[b].end()) cnt=min(cnt, square((*tmp)-i)); 
		if(tmp!=s[b].begin()) cnt=min(cnt, square((*(--tmp))-i)); 
	}
	return cnt; 
}

int main(){
    int t;
	cin>>t;
	while(t--){
        int n, m;
		cin>>n>>m;
		for(int i=1; i<=n; i++){
            p[i]=i;
            s[i].clear();
        }
		for(int i=1; i<=m; i++){
            int a, b;
			cin>>a>>b;
            p[Find(a)]=Find(b);
        }
		for(int i=1; i<=n; i++){
            s[Find(i)].insert(i);
        }
		int st=p[1], en=p[n];
        ll ans=len(st, en); 
		for(int i=1; i<=n; i++){
			if(p[i]==st||p[i]==en||p[i]!=i) continue; 
			ans=min(ans, len(i, st)+len(i, en)); 
		}
		cout<<ans<<'\n';
	}
	return 0;
}