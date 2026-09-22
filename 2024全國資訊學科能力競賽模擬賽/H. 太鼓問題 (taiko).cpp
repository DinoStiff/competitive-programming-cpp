#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
ll dp[N][2];
int main(){
    minji;
    ll n, l, r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    for(int i=2;i<n;i++){
        if(s[i-1]=='.'){
            if(s[i]==s[i-2]||s[i-2]=='.'){
                dp[i][0]=dp[i][1]=min(dp[i-1][0], dp[i-1][1]);
            }
            else{
                dp[i][0] = min(dp[i-2][1], dp[i-2][0]+l);
                dp[i][1] = min(dp[i-2][0], dp[i-2][1]+r);
            }
            continue;
        }
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        if(s[i]!='.'&&s[i]!=s[i-2]&&s[i-2]!='.'){
            dp[i][0]+=l;
            dp[i][1]+=r;
        }
    }
    //cout<<'\n';
    // for(int j=0;j<2;j++){
    //     for(int i=0;i<n;i++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<min(dp[n-1][0], dp[n-1][1])<<'\n';
}