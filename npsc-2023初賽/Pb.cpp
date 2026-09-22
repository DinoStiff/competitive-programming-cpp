#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e6;
const int N = 188, M = 18;

int type[1<<M][N], cnt[1<<M], dp[1<<M];

int main(){
    star;
    memset(dp, INF, sizeof dp);
    int n, m, t;
    char c;
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if(c=='O'){
                type[1<<(m-j-1)][i] = 1;
            }
        }
        type[0][i]=1;
    }
    cnt[0] = n;
    dp[0] = 0;
    for(int i = 1;i < (1<<m);i++){
        int tmp;
        for(int j=0;j<m;j++){
            if(i&(1<<j)){
                tmp = j;
                dp[i] = min(dp[i], dp[i^(1 << j)] + cnt[i^(1<<j)]*t);
            }
        }
        for(int j=0;j<n;j++){
            type[i][j] = type[i^(1 << tmp)][j] & type[1<<tmp][j];
            cnt[i]+=type[i][j];
        }
        //cout<<i<<' '<<cnt[i]<<' '<<dp[i]<<endl;
    }
    cout<<dp[(1<<m)-1]<<endl;
}