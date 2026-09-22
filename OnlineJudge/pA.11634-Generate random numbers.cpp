#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int n;
    bool vis[10004];
    while (cin >> n && n) {
        memset(vis, 0, sizeof vis);
        int ans = 0;
        while (!vis[n]) {
            ans++;
            vis[n] = 1;
            n = (n * n) / 100 % 10000;
        }
        cout << ans << '\n';
    }
}