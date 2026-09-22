#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 5e5+7;

vector<pii> v[N];
ll n, maxlen, minlen, maxpos;
int edge[N];

void dfs1(int x, int p, ll l){
    if(l>maxlen){
        maxlen = l;
        maxpos = x;
    }
    for(pii i:v[x]){
        if(i.first!=p){
            dfs1(i.first, x, l+i.second);
        }
    }
}

void dfs2(int x, int p, ll l){
    if(v[x].size()==1&&p){
        if(l<minlen){
            minlen = l;
        }
    }
    if(l>minlen)
        return;
    for(pii i:v[x]){
        if(i.first!=p){
            dfs2(i.first, x, l+i.second);
        }
    }
}

int main(){
    minji;
    cin>>n;
    for(int i=1;i<n;i++){
        ll x, y, z;
        cin>>x>>y>>z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
        edge[x]++;
        edge[y]++;
    }
    maxlen = 0;
    dfs1(1, 0, 0);
    maxlen = 0;
    minlen = INF;
    dfs1(maxpos, 0, 0);
    int cnt=0;
    for(int i=1;i<=n/2;i++){
        if(edge[i]==1){
            dfs2(i, 0, 0);
            cnt++;
        }
        if(edge[n-i+1]==1){
            dfs2(n-i+1, 0, 0);
            cnt++;
        }
        if(cnt==200)
            break;
    }
    
    cout<<maxlen<<' '<<minlen<<'\n';
}