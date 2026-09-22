#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int t, m, n, q;

bool check(vector<string> &v, int x, int y, int r) {
    if (x < 0 || x >= m || y < 0 || y >= n) return 0;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            if (x + i < 0 || x + i >= m || y + j < 0 || y + j >= n)
                return 0;
            if (v[x + i][y + j] != v[x][y]) return 0;
        }
    }
    return 1;
}


int main(){
    minji;
    int x, y, l, r;
    cin >> t;
    while (t--) {
        cin >> m >> n >> q;
        vector<string> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }
        cout << m << " " << n << " " << q << '\n';
        while (q--) {
            cin >> x >> y;
            l = 0, r = min(m, n);
            while (l <= r) {
                int mid = (l + r) / 2;
                if (check(v, x, y, mid)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            cout << 2 * r + 1 << '\n';
        }
    }
}