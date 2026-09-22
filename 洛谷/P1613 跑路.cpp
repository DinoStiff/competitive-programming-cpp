#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll dis[55][55], ok[33][55][55];

int main(){
    minji;
    for(int i=1;i<=50;i++){
        for(int j=1;j<=50;j++){
            dis[i][j]=INF;
        }
    }
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        dis[x][y]=1;
        ok[0][x][y]=1;
    }
    for(int d=1;d<=32;d++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(ok[d-1][i][k]&&ok[d-1][k][j]){
                        ok[d][i][j]=1;
                        dis[i][j]=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    cout<<dis[1][n]<<'\n';
}