#include<bits/stdc++.h>
using namespace std;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
struct loc {
    int r, c;
    bool ok(const vector<vector<int>> &a) {
        return r < 0 || c < 0 || r >= a.size() || c >= a[0].size() || a[r][c] == -1;
    }
    loc run(int dir) {
        return {r + dx[dir], c + dy[dir]};
    }
    bool operator < (const loc & b) const {
        return r < b.r || (r == b.r && c < b.c);
    }
};
int explode(const vector<vector<int>> &a, vector<vector<int>> &used, loc x);
int bfs(const vector<vector<int>> &a, vector<vector<int>> &used, loc pos) {
    int cnt = 0;
    queue<loc> bfs;
    bfs.push(pos);
    map<loc, int> dis;
    dis[pos] = 0;
    while(!bfs.empty()) {
        auto me = bfs.front();
        bfs.pop();
        cnt += explode(a, used, me);
        int my_dis = dis[me];
        if(my_dis == a[pos.r][pos.c]) continue;
        for(int dir = 0; dir < 4; dir++) {
            loc nxt = me.run(dir);
            if(nxt.ok(a) || dis.count(nxt)) continue;
            dis[nxt] = my_dis + 1;
            bfs.push(nxt);
        }
    }
    return cnt;
}

int explode(const vector<vector<int>> &a, vector<vector<int>> &used, loc x) {
    if(used[x.r][x.c]) return 0;
    used[x.r][x.c] = 1;
    int cnt = 1;
    if(a[x.r][x.c] > 0) cnt += bfs(a, used, x);
    return cnt;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int m, n, q;
    cin >> m >> n >> q;
    vector<vector<int>> a(m, vector<int>(n));
    loc ini;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            cin >> a[i][j];
            if(a[i][j] == -2) ini = {i, j};
        }
    }

    queue<loc> que;
    vector<vector<int>> vis(m, vector<int>(n));
    vector<vector<int>> dis(m, vector<int>(n));
    que.push(ini);
    vis[ini.r][ini.c] = 1;
    vector<vector<loc>> pos(n * m);
    while(!que.empty()) {
        auto me = que.front();
        que.pop();
        pos[dis[me.r][me.c]].push_back(me);
        for(int dir = 0; dir < 4; dir++) {
            loc nxt = me.run(dir);
            if(nxt.ok(a) || vis[nxt.r][nxt.c]) continue;
            que.push(nxt);
            vis[nxt.r][nxt.c] = 1;
            dis[nxt.r][nxt.c] = dis[me.r][me.c] + 1;
        }
    }
    vector<vector<int>> used(m, vector<int>(n));
    int num = 0;
    for(int ans = 0; ;ans++) {
        for(auto x: pos[ans]) num += explode(a, used, x);
        if(num >= q) {
            cout << ans << '\n';
            return 0;
        }
    }
}