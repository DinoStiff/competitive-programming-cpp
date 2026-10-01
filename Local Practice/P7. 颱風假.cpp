#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e2;

int d[N+1][N+1];

int main(){
    minji;
    int n, m, k;
    cin>>n>>m>>k;
    while(n--){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for(int l = 0; l < N; l++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
    vector<pii> worker;
    vector<int> vac;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        worker.push_back({x, y});   
    }
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        vac.push_back(x);
    }
    for(auto [i, j]:worker){
        bool ok=1;
        for(auto c:vac){
            if(d[i][j]==d[i][c]+d[c][j]){
                ok=0;
                break;
            }
        }
        if(ok)
            cout<<1<<' ';
        else{
            cout<<9<<' ';
        }
    }
}