#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
  
int n, m, vis[100005], stk[100005], low[100005], fa[100005], in[100005], arr[100005], idx2, idx;
long long coin[100005], dp[100005], ans;
vector <int> v[200005], v2[200005];
stack <int> st;
  
void dfs(int x){
    idx++;
    vis[x] = low[x] = idx;
    st.push(x);
    stk[x] = 1;
    for (auto i:v[x]){
        if (!vis[i]){
            dfs(i);
            low[x] = min(low[x], low[i]);
        }
        else if (stk[i]){
            low[x] = min(low[x], vis[i]);
        }
    }
    if (vis[x] == low[x]){
        idx2++;
        fa[x] = idx2;
        int nxt = -1;
        while (nxt != x){
            nxt = st.top();
            st.pop();
            fa[nxt] = idx2;
            stk[nxt] = 0;
        }
    }
}
void build(){
    for (int i = 1; i <= n; i++){
        coin[fa[i]] += arr[i];
        for (int j:v[i]){
            if (fa[i] != fa[j]){
                v2[fa[i]].push_back(fa[j]);
                in[fa[j]]++;
            }
        }
    }
}
void solve(){
    queue <int> q;
    for (int i = 1; i <= idx2; i++){
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int now = q.front();
        q.pop();
        dp[now] += coin[now];
        ans = max(ans, dp[now]);
        for (auto i:v2[now]){
            in[i]--;
            dp[i] = max(dp[i], dp[now]);
            if (!in[i]) q.push(i);
        }
    }
}
  
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]) dfs(i);
    }
    build();
    solve();
    cout << ans << "\n";
}