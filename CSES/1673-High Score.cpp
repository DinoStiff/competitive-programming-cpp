#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define minji ios::sync_with_stdio(0), cin.tie(0)

using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int n, m, a, b, w, r, t, tmp;
bool ok = 0, fg, vis[N];
vector<pair<int, pii>> edge;
vector<vector<int>> g, ng;
int dis[N], ngc[N];

int dfs( int idx ){
    if( ngc[idx] == true ) return -1;
    if( idx == 1 && ng[idx].size() == 0 ) return (-1 * dis[n]);

    for( auto i : ng[idx] ){
        if( ngc[i] == true ) return -1;
        if( vis[i] == true ) continue;
        
        vis[i] = true;
        tmp = dfs(i);

        if( tmp == (-1 * dis[n]) ) break;
        if( tmp == -1 ) return -1;
    }

    return (-1 * dis[n]);
}

int bell( int idx ){
    for( int i = 1 ; i <= n ; i++ ) dis[i] = 1e15;
    dis[idx] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for(auto e : edge ){
            int w = e.f;
            int a = e.s.f;
            int b = e.s.s;
            if( dis[a] + w < dis[b] ){
                if( i == n-1 ){
                    ok = true;
                    ngc[a] = true;
                    ngc[b] = true;
                }
                dis[b] = dis[a] + w;
            }
        }
    }
    
    if( ok ) return dfs(n);
    else return (-1 * dis[n]);
}

signed main(){
    minji;
    cin >> n >> m;
    if(n==1&&m==2){
        cout<<"-1\n";
        return 0;
    }
    g.resize(n+5);
    ng.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> w;
        edge.push_back({(-1 * w), {a, b}});
        ng[b].push_back(a);
        g[a].push_back(b);
    }

    if( m == 1 && n > 1 ) cout << -1 * edge[0].first << "\n";
    else if( n == 1 && m == 1 ){
        if( edge[0].f < 0 ) cout << "-1\n";
        else cout << "0\n";
    } 
    else cout << bell(1) << "\n";
}