#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
	string n;
	int m, s;
	cin >> n >> m;
	
	s = n.size();
	vector dp(s+1,vector(2,vector(m+1,0LL)));
	dp[0][0][0] = 1;

	for (int i=0; i<s; i++) {
		for (int ii=0; ii<2; ii++) {
			for (int j=0; j<=9; j++) {
				for (int k=0; k<=m; k++) {
					if (j==0) {
						int tmp = ii | (n[i]>'0');
						dp[i+1][tmp][k] += dp[i][ii][k];
					}
					else if (j<=(n[i]-'0') && k<m) {
						int tmp = ii | (n[i]>'0'+j);
						dp[i+1][tmp][k+1] += dp[i][ii][k];
					}
					else if (ii==1 && k<m) {
						dp[i+1][ii][k+1] += dp[i][ii][k];
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i=0; i<2; i++) {
		ans += dp[s][i][m];
	}
	cout << ans << "\n";
    return 0;
}
