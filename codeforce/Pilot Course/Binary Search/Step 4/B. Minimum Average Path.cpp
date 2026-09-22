#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e5+7;

int n, m;
vector<pii> v[N];
bool good(double k) {
    vector<double> dp(N, INF);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [j, w] : v[i]) {
            dp[j] = min(dp[j], dp[i] + w - k);
        }
    }

    return dp[n] <= 0;
}
int main(){
    star;
    cin >> n >> m;

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    double l = 0, r = 100;
    for (int i = 0; i < 80; i++) {
        double k = (l + r) / 2;
        if (good(k)) {
            r = k;
        } else {
            l = k;
        }
    }

    vector<double> dp(N, INF);
    vector<int> p(N);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [j, w] : v[i]) {
            if (dp[j] > dp[i] + w - l) {
                p[j] = i;
                dp[j] = dp[i] + w - l;
            }
        }
    }

    vector<int> ans;
    int x = n;
    while (x != 1) {
        ans.push_back(x);
        x = p[x];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    cout << ans.size() - 1 << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}