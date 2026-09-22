#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;


vector<vector<int>> v;
vector<bool> vis;

int dfs(int x) {
    vis[x] = true;
    int res = 1;
    for (int i : v[x]) {
        if (!vis[i]) {
            res += dfs(i);
        }
    }
    return res;
}
int main() {
    minji;
    int t, n, m, l;
    cin >> t;
    while (t--) {
        cin >> n >> m >> l;
        v.clear();
        v.resize(n+1);
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        int ans = 0;
        vis.assign(n, 0);
        for (int i=0; i<l; i++) {
            int a;
            cin >> a;
            if (!vis[a]) {
                ans += dfs(a);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
