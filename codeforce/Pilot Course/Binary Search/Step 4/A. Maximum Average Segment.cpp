#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

int n, d;
vector<int> v(N);

pair<int,int> good(double m) {
    vector<double> pre(n+1), tmp(n+1);
    vector<int> idx(n+1);

    pre[0] = v[0] - m;
    tmp[0] = pre[0];
    idx[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + v[i] - m;

        if (pre[i] < tmp[i-1]) {
            tmp[i] = pre[i];
            idx[i] = i;
        } else {
            tmp[i] = tmp[i-1];
            idx[i] = idx[i-1];
        }
    }

    for (int i = d; i <= n; i++) {
        if (pre[i] >= tmp[i-d]) {
            int l = idx[i-d] + 1;
            return {l, i};
        }
    }

    return {-1, -1};
}


int main(){
    star;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    double l = -1, r = 101;

    pair<int,int> cur, ans;
    for (int i = 0; i < 100; i++) {
        double k = (l + r) / 2;
        cur = good(k);
        if (cur.first == -1) {
            r = k;
        } else {
            ans = cur;
            l = k;
        }
    }

    cout << ans.first << " " << ans.second << endl;
}