#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
const ll mod = 1e9+7;

int pos[N], n, m, q, e[2];
vector<pair<int, ll>> v[N];
ll cost[2][N], way[2][N];
bool vis[2][N];

void dijkstra(){
    for(int t=0;t<2;t++){
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, e[t]});
        cost[t][e[t]] = 0;
        way[t][e[t]] = 1;
        while(pq.size()){
            pii tmp = pq.top();
            pq.pop();
            //cout<<tmp.first<<' '<<tmp.second<<'\n';
            if(vis[t][tmp.second]) continue;
            vis[t][tmp.second] = 1;
            for(auto i:v[tmp.second]){
                if(tmp.first + i.second < cost[t][i.first]){
                    cost[t][i.first] = tmp.first + i.second;
                    way[t][i.first] = way[t][tmp.second];
                    pq.push({cost[t][i.first], i.first});
                }
                else if(tmp.first + i.second == cost[t][i.first]){
                    way[t][i.first] += way[t][tmp.second];
                    way[t][i.first] %= mod;
                }
            }
        }
    }
}

int main(){
    star;
    cin>>n>>m>>q>>e[0]>>e[1];
    for(int i=0;i<q;i++){
        cin>>pos[i];
    }
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        cost[0][a] = cost[0][b] = cost[1][a] = cost[1][b] = INF;
    }
    dijkstra();
    for(int i=0;i<q;i++){
        cout<<cost[0][pos[i]]+cost[1][pos[i]]<<' '<<way[0][pos[i]]*way[1][pos[i]]%mod<<'\n';
    }
}