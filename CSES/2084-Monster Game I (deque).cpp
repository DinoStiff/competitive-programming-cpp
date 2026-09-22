#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int, int>

signed main() {
    int n, k;
    cin >> n >> k;
    vector<pii> l = {{k, 0}};
    vector<int> v = {1};
    int s[n], f[n];
    for (auto &i: s)
        cin >> i;
    for (auto &i: f)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i];
        int it = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
        int m = f[i];
        ans = x*l[it].first + l[it].second;
        if (l.back().first == m) continue;
        while (l.size() >= 2) {
            auto y2 = l[l.size() - 1];
            auto y3 = l[l.size() - 2];
            if ((y2.second - ans)*(m - y3.first) < (y3.second - ans)*(m - y2.first)) {
                l.pop_back();
                v.pop_back();
            }
            else break;
        }
        int x1 = ceil((l.back().second - ans)*1.0/(m - l.back().first));
        v.push_back(x1);
        l.push_back({m, ans});
    }
    cout << ans << endl;
}