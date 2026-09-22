#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, m, x, a, b, ans;
set <int> s[10005];
queue <pii> q;
 

int main(){
    minji;
    cin >> n >> m >> x;
    for (int i = 0; i < x; i++){    
        cin >> a >> b;
        s[a].insert(b);
    }
    for (int k = 1; k <= n; k++){
        while (!s[k].empty()){
            ans++;
            q.push({k, *(s[k].begin())});
            s[k].erase(s[k].begin());
            while (!q.empty()){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int i = max(1, x-2); i <= min(n, x+2); i++){
                    for (int j = max(1, y-2); j <= min(m, y+2); j++){
                        if (!s[i].count(j)) continue;
                        s[i].erase(j);
                        q.push({i, j});
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}