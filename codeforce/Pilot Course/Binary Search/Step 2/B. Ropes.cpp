#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto& x: v) {
        cin >> x;
    }

    double l = 0, r = 1e8;

    for (int i = 0; i < 50; i++) {
        double m = (l + r) / 2;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += (int)(v[j] / m);
        }
        if (cnt >= k) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << setprecision(10) << l << endl;

}