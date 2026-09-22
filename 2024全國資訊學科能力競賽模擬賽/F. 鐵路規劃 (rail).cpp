#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int M = 1e6+7, N = 5e5+7;

char c[M];
int vis[M];
vector<vector<pii>> v(N);
int edge[N], amt[N][2];

void dfs(int x, char color){
    for(auto i:v[x]){
        if(!vis[i.second]){
            vis[i.second]=1;
            c[i.second]=color;
            color=(color=='R'? 'B':'R');
            dfs(i.first, color);
        }
    }
}

int main(){
    minji;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
        edge[x]++;
        edge[y]++;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(edge[i]==1){
            dfs(i, 'R');
            break;
        }
        cnt++;
    }
    if(cnt==n)
        dfs(1, 'R');
    for(int i=0;i<m;i++){
        cout<<c[i];
    }
    cout<<"\n";
}