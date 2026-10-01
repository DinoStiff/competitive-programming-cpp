#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll dp[N];

int main(){
    minji;
    ll n;
    cin>>n;
    ll x, y;
    while(cin>>x>>y){
        for(int i=n;i>=x;i--){
            dp[i]=max(dp[i], dp[i-x]+y);
        }
    }
    cout<<dp[n]<<'\n';
}