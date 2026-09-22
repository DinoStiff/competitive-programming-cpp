#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e14;
const int N = 1e5+7;

int n, k;
vector<int> v;

bool good(ll m) {
    ll sum = 0, num = 1;
    for (int i = 0; i < n; i++) {
        if(v[i] > m) return 0;
        if (sum + v[i] > m) {
            sum = v[i];
            num++;
        } else {
            sum += v[i];
        }
    }
    return num <= k;
    
}

int main() {
    star;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    ll l = 1, r = INF;

    while(l < r){
        ll m = (l + r) / 2;

        if (good(m)) {
            r = m;
        } else {
            l = m+1;
        }
    }

    cout << l << endl;

}