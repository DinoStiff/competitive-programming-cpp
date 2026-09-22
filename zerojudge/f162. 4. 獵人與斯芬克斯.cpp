#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 3e5+1;
ll k, n, m, ans;
vector<vector<int>> pre, col, row;


void solve(int u, int d){
    set<ll> s;
    s.insert(0);
    ll dp[m+7];
    //cout<<u<<' '<<d<<'\n';
    for(int i=1;i<=m;i++){
        auto tmp = s.lower_bound(pre[d][i]-pre[u-1][i]-k);
        if(tmp==s.end())
            dp[i]=0;
        else{
                dp[i] = pre[d][i]-pre[u-1][i]-*tmp;
        }
        s.insert(pre[d][i]-pre[u-1][i]);
        ans = max(ans, dp[i]);
        //cout<<dp[i]<<' ';
    }
    //cout<<"\n\n";
}

int main(){
    star;
    cin>>k;
    cin>>n>>m;
    pre.resize(n+5, vector<int>(m+5, 0));
    col.resize(n+5, vector<int>(m+5, 0));
    row.resize(n+5, vector<int>(m+5, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;
            cin>>a;
            col[i][j]=col[i-1][j]+a;
            row[i][j]=row[i][j-1]+a;
            pre[i][j] = pre[i-1][j-1]+col[i][j]+row[i][j]-a;
            //cout<<pre[i][j]<<' ';
        }
        //cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            solve(i, j);
        }
    }
    cout<<ans<<'\n';
}