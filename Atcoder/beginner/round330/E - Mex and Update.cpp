#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll tmp, n, q;
ll vis[N], a[N], idx, val;
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
	minji;
	cin >> n >> q;
	tmp = n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] > tmp) a[i] = tmp+1;
		vis[a[i]]++;
	}
	for(int i=0; i<=n; i++){
		if(vis[i]==0){
			pq.push(i);
		}
	}
	for(int i=1; i<=q; i++){
		cin >> idx >> val;
		if(val > tmp) val=tmp+1;
		vis[a[idx]]--;
		vis[val]++;
		if(vis[a[idx]]==0){
			pq.push(a[idx]);
		}
		a[idx]=val;
		while(vis[pq.top()]){
			pq.pop();
		}
		cout<<pq.top()<<'\n';
	}
	return 0;
}
