#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
  
int n, cnt[N], dp[N], ans[N];
vector <int> v[N];
  
int dfs(int x, int pre){
    if (cnt[x]) dp[x] = 1;
    else dp[x] = -1;
    for (int i:v[x]){
        if (i == pre) continue;
        int res = dfs(i, x);
        if (res > 0) dp[x] += res;
    }
    return dp[x];
}
void dfs2(int x, int pre){
    for (int i:v[x]){
        if (i == pre) continue;
        int tmp = ans[x];
        if (dp[i] > 0) tmp -= dp[i];
        ans[i] = dp[i];
        if (tmp > 0) ans[i] += tmp;
        dfs2(i, x);
    }
}
  
int main(){
    nice;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> cnt[i];
    }
    int x, y;
    for (int i = 1; i < n; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);
    cout << ans[1];
    for (int i = 2; i <= n; i++){
        cout << " " << ans[i];
    }
    cout << "\n";
}