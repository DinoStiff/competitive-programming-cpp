#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
 
int n;
vector<vector<pair<int, ull>>> graph;
vector<bool> vis;
vector<ull> d;
vector<ull> v;
 
void add(ull x) {
    for (ull b : v) {
        x = min(x, x ^ b);
    }
    if (x) {
        v.push_back(x);
        sort(v.rbegin(), v.rend());
    }
}
 
void dfs(int x, int f) {
    vis[x] = true;
    for (auto &edge : graph[x]) {
        int nxt = edge.first;
        ull w = edge.second;
        if (nxt == f) continue;
        if (!vis[nxt]) {
            d[nxt] = d[x] ^ w;
            dfs(nxt, x);
        } else {
            add(d[x] ^ w ^ d[nxt]);
        }
    }
}
 
int main(){
    minji;
 
    int m;
    cin >> n >> m;
    graph.resize(n + 1);
    vis.assign(n + 1, false);
    d.assign(n + 1, 0);
 
    for (int i = 0; i < m; i++){
        int u, v;
        ull w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
 
    dfs(1, -1);
    ull ans = d[n];
    for (ull b : v) {
        if ((ans ^ b) < ans) {
            ans ^= b;
        }
    }
 
    cout << ans << "\n";
    return 0;
}
