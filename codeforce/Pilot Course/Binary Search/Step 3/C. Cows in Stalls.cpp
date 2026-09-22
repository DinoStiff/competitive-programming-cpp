#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e9+7;
const int N = 1e4+7;

int n, k;
vector<int> v(N);
bool good(int m) {
    int cnt = 1;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] - v[idx] >= m) {
            cnt++;
            idx = i;
        }
    }

    return cnt >= k;
}

int main(){
    star;

    cin >> n >> k;

 

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 0, r = INF;

    while (r > l + 1) {
        int m = (l + r) / 2;
        if (good(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;
}
