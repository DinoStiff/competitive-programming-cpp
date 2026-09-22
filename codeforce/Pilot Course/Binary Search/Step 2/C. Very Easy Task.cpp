#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e10;
const int N = 2e5+7;

ll n, x, y;

bool good(ll k) {
    ll sum = 1;
    k -= x;
    sum += k / x + k / y;
    return sum >= n;
}

int main(){
    star;
    cin >> n >> x >> y;

    ll l = x, r = INF;
    if(x>y)
        swap(x, y);
        
    while (r > l) {
        ll k = (l + r) / 2;
        if (good(k)) {
            r = k;
        } else {
            l = k+1;
        }
    }

    cout << l << endl;
}