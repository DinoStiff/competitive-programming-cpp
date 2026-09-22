#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)

using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

vector<int> v[N];

int vis[N], dp[N];

int main(){
    star;
    int n, m;
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		vis[b]++;
	}
	
	queue<int> q;
	for(int i=1;i<=n;i++){
        if(!vis[i]) q.push(i);
    }
	
	int ans=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		ans=max(ans,dp[x]);
		for(int i:v[x]) {
			dp[i]=max(dp[i],dp[x]+1);
			if(!--vis[i]) q.push(i);
		}
	}
	
	cout << ans << '\n';
}