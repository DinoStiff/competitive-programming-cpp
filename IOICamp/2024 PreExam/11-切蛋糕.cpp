#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    star;
    int n, m;
    cin>>n>>m;
    int a[n+1][m+1], row[n+1], col[m+1], dp[n][m], ans[n*m+1];
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(ans, -1, sizeof ans);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            row[i-1]+=a[i][j];
            row[i]+=a[i][j];
            col[j-1]+=a[i][j];
            col[j]+=a[i][j];
            dp[0][0]+=a[i][j];
        }
    }
    sort(row+1, row+n, cmp);
    sort(col+1, col+m, cmp);
    ans[1] = dp[0][0]+=row[0]+row[n]+col[0]+col[m];
    col[0]=row[0]=0;
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]+row[i];
        ans[i+1] = max(ans[i+1], dp[i][0]);
    }
    for(int i=1;i<m;i++){
        dp[0][i] = dp[0][i-1]+col[i];
        ans[i+1] = max(ans[i+1], dp[0][i]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = max(dp[i-1][j]+row[i], dp[i][j-1]+col[j]);
            ans[(i+1)*(j+1)] = max(ans[(i+1)*(j+1)], dp[i][j]);
        }
    }
    for(int i=1;i<=n*m;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}