#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2501;

bool vis[N];
int n, m, ans, p[N], dis[N];
vector<int> v[N];

    

void bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        for(int i : v[idx]){
            if(!vis[i]){
                dis[i] = dis[idx]+1;
                vis[i] = 1;
                p[i] = idx;
                q.push(i);
            } else if(i != p[idx]){
                ans = min(ans, dis[idx]+dis[i]+1);
            }
        }
    }
}

int main(){
    minji;
    cin>>n>>m;
    for(int i = 0, a, b; i < m; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    ans = n+1;
    for(int i = 1; i <= n; i++){
        fill(vis+1, vis+n+1, false);
        fill(dis+1, dis+n+1, 0);
        fill(p+1, p+n+1, 0);
        bfs(i);
    }

    cout<< (ans == n+1 ? -1 : ans)<<'\n';
}