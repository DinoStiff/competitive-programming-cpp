#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 345;

int nxt[100005], pos[100005], sum[505][505];
vector<int> v[100005];

signed main() {
    minji;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[x].push_back(i);
        if (v[x].size() > k) {
            int tmp = v[x][v[x].size() - k - 1];
            nxt[tmp] = i, pos[i] = tmp;
            sum[tmp / N][i / N]++;
        }
    }
    for (int i = 2; i <= n / N + 1; i++) {
        for (int j = 0; j <= n / N - i + 2; j++) {
            int k = j + i - 1;
            sum[j][k] += sum[j + 1][k] + sum[j][k - 1] - sum[j + 1][k - 1];
        }
    }
    int ls = 0;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (l + ls) % n + 1;
        r = (r + ls) % n + 1;
        if (l > r) swap(l, r);
        if (r - l <= N) {
            int ans = 0;
            for (int i = l; i <= r; i++) ans += nxt[i] && nxt[i] <= r;
            cout << (ls = r - l + 1 - ans) << "\n";
            continue;
        }
        int ans = sum[l / N + 1][r / N - 1], L = l / N * N + N, tmp = r / N * N - 1;
        for (int i = l; i < L; i++) ans += nxt[i] && nxt[i] <= r;
        for (int i = tmp + 1; i <= r; i++) ans += pos[i] && pos[i] >= L;
        cout << (ls = r - l + 1 - ans) << "\n";
    }
    return 0;
}