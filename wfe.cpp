#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define good_luck ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
int a, dp[206];

int main(){
    good_luck;
    int n, ans=0;
    cin>>n;

    cin>>dp[1];
    for(int i=2;i<=n;i++){
        cin>>a;
        dp[i]=max(a+dp[i-2], dp[i-1]);
    }

    cout<<dp[n]<<"\n";

}