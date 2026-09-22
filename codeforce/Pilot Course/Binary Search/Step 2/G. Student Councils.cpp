#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 57;

int k, n;
vector<ll> v;

bool good(ll m) {
    ll sum = 0;

    for (auto i : v) {
        sum += min(m, i);
    }

    return sum >= m * k;
}

int main(){
    star;

    cin >> k >> n;
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    ll l = 0, r = INF;
    while (l+1<r) {
        ll m = (l + r) / 2;
        if (good(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';

}