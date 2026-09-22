#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int n = 2e5+7;

int main(){
    minji;
    int n;
    cin >> n;
    vector<string> v(n);
    vector<int> col(n), row(n);
    for (auto& i : v) cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'o') col[j]++, row[i]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'o') ans += (col[j] - 1) * (row[i] - 1);
        }
    }
    cout << ans << '\n';
}
