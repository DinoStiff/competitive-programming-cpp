#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

ll dp[N], w[200], v[200];

int main(){
    star;

	for(int i=1;i<=N;i++)
		dp[i]=INF;

    int n, m;
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=N;j>=w[i];j--){
			dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	for(int i=N;i>=0;i--){
		if(dp[i]<=m) {
			cout<<i<<endl;
			return 0;
		}
	}
}