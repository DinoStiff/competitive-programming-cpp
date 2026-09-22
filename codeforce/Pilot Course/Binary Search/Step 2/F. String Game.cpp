#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

string a, b;
vector<int> v(N);

bool good(int k) {
    int idx = 0;

    for (int i = 0; i < a.size() && idx < b.size(); i++) {
        if (v[i] <= k) continue;
        if (a[i] == b[idx]) {
            idx++;
        }
    }
    return idx == b.size();
}

int main(){
    star;

    cin >> a >> b;

    int x;

    for (int i = 1; i <= a.size(); i++) {
        cin >> x;
        v[x-1] = i;
    }

    int l = 0;
    int r = a.size();
    while (r > l + 1) {
        int k = (l + r) / 2;
        if (good(k)) {
            l = k;
        } else {
            r = k;
        }
    }

    cout << l << endl;

}