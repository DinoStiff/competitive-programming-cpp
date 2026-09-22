#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define good_luck ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e9+7;
const int N = 105;
int n, m;
int s, t, k, h[N]; 
bool vis[N];
struct node {
    int x, dis;
};

int g[N][N], g2[N][N];

bool operator < (const node& a, const node& b) {
    return (a.dis + h[a.x] > b.dis + h[b.x]);
}

int solve() {
    priority_queue<node> q;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n + 1; i++)
        h[i] = INF;
    h[t] = 0;
    for(int i = 1; i <= n; i++) {
        int x, m = INF;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && m > h[j]) {
                m = h[j];   
                x = j;
            }
        }
        vis[x] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && g2[x][j] + h[x] < h[j]) {
                h[j] = g2[x][j] + h[x];
            }   
        }
    }
    if (s == t) k++;
    if (h[s] == INF) return -1;
    int ans = -1, cnt = 0;
    node now;
    now.x = s;
    now.dis = 0;
    q.push(now);
    while(!q.empty()) {
        now = q.top(); q.pop();
        if (now.x == t) cnt++;
        if (cnt == k) {
            ans = now.dis;    
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (g[now.x][i] != INF) {
                q.push((node){i, now.dis + g[now.x][i]});    
            }   
        }
    }
    return ans;
}

int main() {
    good_luck;
    while (cin>>n>>m&&n&&m) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                g[i][j] = INF;    
                g2[i][j] = INF;
            }
        }
        cin>>s>>t>>k;
        int u, v, d;
        for (int i = 0; i < m; i++) {
            cin>>u>>v>>d;
            g[u][v] = min(g[u][v], d);
            g2[v][u] = min(g2[v][u], d);
        }
        cout<<solve()<<"\n";
    }
    return 0;
}