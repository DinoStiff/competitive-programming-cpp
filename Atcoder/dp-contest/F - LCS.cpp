#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 4000;

int dp[N][N];

int main(){
    star;
    string s, t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    string ans;
    int x = n, y = m;
    while (x && y) {
        if (s[x-1] == t[y-1]) {
            ans += s[x-1];
            x--, y--;
        }
        else if (dp[x][y-1] >= dp[x-1][y]) {
            y--;
        }
        else x--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}