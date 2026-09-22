#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
 
const ll INF = 1e18, N = 5e3 + 7;
 
vector<pii> v[N];
ll n, m;
ll dis[N][N];
 
int main() {
    cin >> n >> m;
    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=INF;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int s, t;
        cin>>s>>t;
        if(dis[s][t]!=INF||dis[t][s]!=INF){
            cout<<dis[s][t]<<'\n';
            continue;
        }
        priority_queue<pii> pq;
        pq.push({0, s});
        while (pq.size()) {
            pii k = pq.top();
            if (dis[s][k.second] == INF) {
                dis[s][k.second] = dis[k.second][s] = -k.first;
                for (auto [i, j] : v[k.second]) {
                    if (dis[s][i] == INF||dis[s][i] == INF) {
                        pq.push({-(j - k.first), i});
                    }
                }
            }
            pq.pop();
        }
        cout << dis[s][t] << endl; 
    }
}
