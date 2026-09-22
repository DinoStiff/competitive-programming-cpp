#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, m, q, t[N], tmp=N, ok[N];
vector<pii> v[N];
signed main(){
    minji;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        int a, b;
		cin>>a>>b;
		ok[i]=-1;
		v[a].push_back({b, i});
	}
	for(int i=1;i<=m;i++){
		if(v[i].size()){
			sort(v[i].begin(), v[i].end());
			t[v[i][0].second]=v[i][0].first-1;
			for(int j=1;j<v[i].size();j++){
				int id=v[i][j].second;
				int l=v[i][j].first;
				t[id]=max(t[v[i][j-1].second]+l-v[i][j-1].first, l-1);
			}
		}
		
		tmp=min(tmp, (int)v[i].size());
	}
	for(int i=0;i<tmp;i++){
		int maxx=0;
		for(int j=1;j<=m;j++){
			maxx=max(maxx, t[v[j][i].second]);
		}
		for(int j=1;j<=m;j++){
			ok[v[j][i].second]=maxx+1;
		}
	}
	cin>>q;
	while(q--){
		int k, idx;
		cin>>k>>idx;
		if(ok[idx]==-1){
			cout<<"Yes\n";
			continue;
		}
		if(ok[idx]<=k)
			cout<<"No\n";
        else
            cout<<"Yes\n";
	}
	return 0;
}
