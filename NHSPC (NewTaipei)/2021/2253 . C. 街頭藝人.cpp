#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e9;
const int N = 100005;

struct edge {
    int t, w, id;
    edge () {}
    edge (int x, int y, int z) { t=x; w=y; id=z; }
};
int n, m;
vector<edge> e[N];
bool dfs(int X, vector<int>& s, vector<bool>& vis, vector<bool>& ins, int cur) {
    vis[cur] = 1;
    ins[cur] = 1;
    for (auto i: e[cur]) if (i.w > X) {
        if (!vis[i.t]) {
            if (!dfs(X, s, vis, ins, i.t)) {
                return 0;
            }
        } else if (ins[i.t]) {
            return 0;
        }
    }
    ins[cur] = 0;
    s.push_back(cur);
    return 1;
}
void solve() {
    vector<int> s;
    vector<bool> vis(n+1, 0);
    vector<bool> ins(n+1, 0);
    auto check = [&](int X){
        s.clear();
        fill(all(vis), 0);
        fill(all(ins), 0);
        for(int i=1;i<=n;i++) if (!vis[i]) {
            if (!dfs(X, s, vis, ins, i)) {
                return 0;
            }
        }
        return 1;
    };

    int ng = -1, ok = INF, mid;
    while (abs(ok-ng) > 1) {
        mid = (ok + ng) / 2;
        if (check(mid)) ok = mid;
        else ng = mid;
    }

    vector<int> ord(n+1);
    vector<int> ans;
    check(ok);
    for(int i=0;i<n;i++) ord[s[i]] = i;
    for(int i=1;i<=n;i++) for (auto j: e[i]) if (ord[i] < ord[j.t]) {
        ans.push_back(j.id);
    }

    cout<<ok<<' '<<(int)ans.size()<<'\n';
    for (int i: ans) {
        cout<<i<<'\n';
    }
}

int main(){
    minji;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1;i<=m;i++) {
        int x, y, z;
        cin>>x>>y>>z;
        e[x].push_back(edge(y, z, i));
    }
    solve();
    return 0;
}