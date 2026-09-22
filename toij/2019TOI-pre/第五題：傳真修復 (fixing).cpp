#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
#define int ll
using namespace std;

const int INF = 1e18;
const int N = 30+7;

bool p[N][N];
int n, m, ans=INF, dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};

void dfs(int x, int y, int cnt){
    if(x==n){
        int tmp = cnt * 2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i)
                    tmp+=(p[i][j]!=p[i-1][j]);
                if(j)
                    tmp+=(p[i][j]!=p[i][j-1]);
            }
        }
        ans = min(ans, tmp);
        return;
    }
    if(y==m){
        dfs(x+1, 0, cnt);
        return;
    }
    int tmp=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny = y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m){
            if(p[x][y]!=p[nx][ny])
                tmp++;
        }
    }
    if(tmp<=2)
        dfs(x, y+1, cnt);
    else{
        p[x][y]^=1;
        dfs(x, y+1, cnt+1);
    }
    return;
}

signed main(){
    star;
    //p2 38%
    /*
    int n, m, ans = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>p[0][i];
    }
    for(int i=1;i<m;i++){
        if(p[0][i]!=p[0][i-1])
            ans++;
    }
    cout<<ans<<'\n';
    */
    //p1 23%

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p[i][j];
        }
    }
    dfs(0, 0, 0);
    cout<<ans<<'\n';
}
