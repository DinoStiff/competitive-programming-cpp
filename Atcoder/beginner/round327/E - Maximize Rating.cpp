#include <bits/stdc++.h>
#define ll long long
#define db double
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
const db c = 0.9;

int main(){
    minji;
	int n;
	cin>>n;
	vector<db> p(n), dp(n+1, 0);
	db w, ans = -1200.0;
	for(int i = 0; i < n; i++)cin>>p[i];
	for(int i = 0;i<n;i++){
		dp[i+1] = c*dp[i]+p[i];
		for(int j = i-1; j >= 0; j--){
			dp[j+1] = max(c*dp[j]+p[i], dp[j+1]);
		}
	}
	w = 0.0;
	for(int i = 1; i <= n; i++){
		w = c*w + 1.0;
		ans = max(ans, dp[i]/w - 1200.0/sqrt((db)i));
	}
	cout<< fixed << setprecision(10) <<ans<<endl;
}