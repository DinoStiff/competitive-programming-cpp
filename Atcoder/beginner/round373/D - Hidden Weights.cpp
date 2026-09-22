#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,-w});
    }
    vector<int> vis(n,0);
    vector<ll> ans(n);
    auto dfs=[&](auto dfs,int u) -> void {
        vis[u]=1;
        for(auto [v,w]:adj[u]){
            if(vis[v]){
                continue;
            }
            ans[v]=ans[u]+w;
            dfs(dfs,v);
        }
        return;
    };
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans[i]=0;
            dfs(dfs,i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i==n-1];
    }
}