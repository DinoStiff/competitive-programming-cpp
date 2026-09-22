#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 5007;

bool pal[N][N];
int dp[N][N];

int main(){
    minji;
    int n, q;
    string s;
    cin>>n>>q;
    cin>>s;
    s.insert(s.begin(), '0');
    for(int i=1;i<=n;i++){
        pal[i][i]=1;
        dp[i][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            if(s[j]==s[i+j-1]){
                if(pal[j+1][i+j-2]||i==2)
                    pal[j][j+i-1]=1;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<pal[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    for(int i=2;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            dp[j][j+i-1]=dp[j+1][j+i-1]+dp[j][j+i-2]-dp[j+1][j+i-2]+pal[j][j+i-1];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }
}