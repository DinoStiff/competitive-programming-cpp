#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

vector<pii> a(N);
vector<double> dp(N, 1e18);

double dis(int i, int j) {
    return sqrt(1.0 * (a[i].first - a[j].first) * (a[i].first - a[j].first) + 1.0 * (a[i].second - a[j].second) * (a[i].second - a[j].second));
}

int main(){
    star;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    dp[0] = 0;
    deque<pair<int, double>> dq;
    double cnt = 0;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && i - dq.front().first + 1 > k)
            dq.pop_front();
        cnt += dis(i-1, i);
        if (!dq.empty())
            dp[i] = min(dp[i], dq.front().second + dis(i, 0) + cnt);
        dp[i] = min(dp[i], dp[i-1] + dis(0, i) + dis(i, 0));
        double tmp = dp[i-1] + dis(0, i);
        while (!dq.empty() && dq.back().second + cnt >= tmp)
            dq.pop_back();
        dq.push_back({i, tmp - cnt});
    }
    cout << fixed << setprecision(16) << dp[n] << endl;
    return 0;
}
