#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e5+7;

int n;
vector<int> x(N), v(N);

bool good(double m) {
    double l = -1e10;
    double r = 1e10;
    for (int i = 0; i < n; i++) {
        double xl = x[i] - m*v[i];
        double xr = x[i] + m*v[i];

        l = max(l, xl);
        r = min(r, xr);

        if (l > r) {
            return 0;
        }
    }
    return 1;
}

int main() {
    star;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }

    double l = 0, r = INF;

    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;

        if (good(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << setprecision(10) << l << endl;

}