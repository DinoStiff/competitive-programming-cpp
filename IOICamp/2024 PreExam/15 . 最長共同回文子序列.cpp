#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
int dp[85][85][85][85], n, m;
string a, b;


int main() {
    star;
    cin >> n >> m;
    cin >> a >> b;
    a.insert(a.begin(), '0');
    b.insert(b.begin(), '0');
    //cout<<a<<' '<<b<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int s1=1;s1+i<=n;s1++){
                int e1 = s1+i;
                for(int s2 = 1;s2+j<=m;s2++){
                    int e2 = s2+j;
                    if (s1 == e1 || s2 == e2) {
                        if (a[s1] == b[s2] || a[s1] == b[e2] || a[e1] == b[s2] || a[e1] == b[e2]){
                            dp[s1][e1][s2][e2] = 1;
                        }
                        else {
                            if (s1 == e1){
                                dp[s1][e1][s2][e2] = max(dp[s1][e1][s2 + 1][e2], dp[s1][e1][s2][e2 - 1]);
                            }
                            if (s2 == e2){
                                dp[s1][e1][s2][e2] = max(dp[s1 + 1][e1][s2][e2], dp[s1][e1 - 1][s2][e2]);
                            }
                        }
                    }
                    else if(a[s1] == a[e1] && b[s2] == b[e2] && a[s1] == b[s2]){
                        dp[s1][e1][s2][e2] = 2 + dp[s1+1][e1-1][s2+1][e2-1];
                    }
                    else {
                        dp[s1][e1][s2][e2] = max({dp[s1 + 1][e1][s2][e2], dp[s1][e1 - 1][s2][e2], dp[s1][e1][s2 + 1][e2], dp[s1][e1][s2][e2 - 1]});
                    }
                }
            }
        }
    }
    cout << dp[1][n][1][m] << '\n';
    return 0;
}