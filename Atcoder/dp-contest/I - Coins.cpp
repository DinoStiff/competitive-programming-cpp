#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 3e3+7;

double arr[N];
double dp[N][N];

int main(){
    star;
    int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0]*(1-arr[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j-1]*arr[i]+dp[i-1][j]*(1-arr[i]);
		}
	}
	double ans=0;
	for(int i=ceil(n/2.0);i<=n;i++){
		ans+=dp[n][i];
	}
	printf("%0.10f",ans);
}