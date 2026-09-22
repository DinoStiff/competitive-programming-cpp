#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

    map<int, int> m;

int main(){
    nice;
    int n, k;
    string s1, s2;
    cin >> n >> k >> s1 >> s2;
 
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int d = s1[i] - s2[i];
 
        while (m.size() && m.begin()->first < i) {
            pii now = *m.begin();
            m[now.first + k] += now.second;
            ans += abs(now.second);
            m.erase(now.first);
        }
        if (m.size() && m.begin()->second * d < 0) {
            m.begin()->second += d;
            if (m.begin()->second == 0)
                m.erase(m.begin());
        } else if (d)
            m[i] += d;
    }
 
    cout << ans << '\n';
    return 0;
}
    