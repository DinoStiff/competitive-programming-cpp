#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Max = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 50;
int pre[N];
bool vis[N];
vector<pair<int, ll>> adj[N];
ll dis[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    priority_queue<pair<ll, int>>  pq;
    pre[s] = -1;
    pq.push({0, s});
    for(int i = 0; i < n; i++)
        dis[i] = Max;
    dis[s] = 0;
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        if(vis[v]) continue;
        vis[v] = true;
        for(auto e : adj[v]){
            int u = e.first;
            ll w = e.second;
            if(dis[u] > dis[v] + w){
                pre[u] = v;
                dis[u] = dis[v] + w;
                pq.push({-dis[u], u});
            }
        }
    }
    if(dis[e] == Max){
        cout << -1 << endl;
        return 0;
    }
    cout << dis[e] << ' ';
    int it = e;
    vector<int> ans;
    while(it != -1){
        ans.push_back(it);
        it = pre[it];
    }
    cout << (int)ans.size() - 1 << endl;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size() - 1; i++)
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    return 0;
}