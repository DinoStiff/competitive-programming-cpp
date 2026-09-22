#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define meteor ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17, N = 1e5+7;

ll n, m, k, need[N], ans=0, vis[N];
vector<ll> key[N], treasure[N];
queue<ll> q;

int main(){
    meteor;
    cin>>n>>m>>k;
    ll t, a;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        q.push(a);
    }
    for(int i=0;i<n;i++){
        need[i]=k;
        for(int j=0;j<k;j++){
            cin>>a;
            key[a].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a;
            treasure[i].push_back(a);
        }
    }
    while(q.size()){
        ll now = q.front();
        if(vis[now]){
            q.pop();
            continue;
        }
        vis[now]=1;
        for(int i:key[now]){
            need[i]--;
            if(need[i]==0){
                //cout<<now<<' '<<i<<'\n';
                for(int j:treasure[i]){
                    if(!vis[j])
                        q.push(j);
                }
                ans++;
            }
        }
        q.pop();
    }
    cout<<ans<<'\n';
}