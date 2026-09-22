#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e5+7;

int n, m;
vector<vector<int>> v(N);
int low[N], dep[N];
bool vis[N];
vector<int> ans;

void dfs(int x, int f, int d){
    int child=0;
    bool ok=0;
    low[x]=dep[x]=d;
    vis[x]=1;
    for(auto i:v[x]){
        if(i!=f){
            if(vis[i])
                low[x]=min(low[x], dep[i]);
            else{
                dfs(i, x, d+1);
                low[x]=min(low[x], low[i]);
                if(x==1)
                    child++;
                else{
                    if(low[i]>=dep[x])
                        ok=1;
                }
            }
        }
    }
    if(x==1){
        if(child>=2)
            ok=1;
    }
    if(ok)
        ans.push_back(x);
}

int main(){
    nice;
    cin>>n>>m;
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 1);
    cout<<ans.size()<<'\n';
    for(auto i:ans)
        cout<<i<<' ';
    cout<<' '; 
}
