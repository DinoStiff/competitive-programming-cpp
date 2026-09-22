#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e5+7;
int n, m, st, ed, p[N], vis[N];
vector<int> ans, v[N];

void dfs(int idx){
    vis[idx] = 1;
    for(int i : v[idx]){
        if(vis[i] == 0){
            p[i] = idx;
            dfs(i);
            if(st)
                return;
        } else if(vis[i] == 1){
            ed = idx;
            st = i;
            return;
        }
    }
    vis[idx] = 2;
}
int main(){
    minji;
    cin>>n>>m;
    for(int i = 0, a, b; i < m; i++){
        cin>>a>>b;
        v[a].push_back(b);
    }

    for(int i = 1; i <= n && !st; i++)
        if(vis[i] == 0)
            dfs(i);

    if(!st){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    ans.push_back(st);
    for(int i = ed; i != st; i = p[i])
        ans.push_back(i);
    ans.push_back(st);
    reverse(ans.begin(), ans.end());

    int k = ans.size();
    cout<<k<<'\n';
    for(int i = 0; i < k; i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
