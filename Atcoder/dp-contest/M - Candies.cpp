#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const ll mod = 1e9+7;
const int N = 1e5+7;

ll dp[N];

int main(){
    star;
    int n, k, a;
    cin>>n>>k;
    dp[0] = 1;
    for(int i=0;i<n;i++){
        cin>>a;
        ll sum = 0;
        for(int j = k-1;j>=k - a;j--){
            sum = (sum + dp[j]) % mod;
        }
        for(int j = k;j>=1;j--){
            dp[j] = (dp[j] + sum) % mod;
            sum = (sum - dp[j-1] + mod) % mod;
            if(j>a){
                sum = (sum + dp[j-a-1]) % mod;
            }
        }
    }
    cout << dp[k] <<'\n';
}