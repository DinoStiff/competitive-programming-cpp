#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
ll dp[N], a[N];

int main(){
    minji;
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) 
        cin>>a[i];
    sort(a, a+n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i-1] < a[i]){
            cout<<dp[i-1]<<'\n';
            return 0;
        }
        dp[i] = dp[i-1] + a[i];
    }
    cout<<dp[n]<<'\n';
}
