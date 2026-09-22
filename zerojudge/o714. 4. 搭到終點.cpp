#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int add(ll x, ll y, int p) {
    int ans = (x + y) % p;
    if(ans < 0) ans += p;
    return ans;
}

int sum(const map<int, int> &pre, int st, int ed, int p) {
    auto ed_it = pre.upper_bound(ed);
    ed_it--;
    if(!st)
        return ed_it->second;
    auto st_it = pre.lower_bound(st);
    st_it--;
    return add(ed_it->second, -st_it->second, p);
}


int main() {
    minji;
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> st(n);
    map<int, vector<int>> bus;
    map<int, int> dp, pre;
    for(int &i: st)
        cin >> i;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x <= m) {
            bus[x].push_back(st[i]);
            pre[x] = dp[x] = 0;
        }
    }
    pre[0] = dp[0] = 1 % p;

    for(auto i = dp.begin(), j = pre.begin(); i != dp.end(); i++, j++) {
        int x = i->first;
        for(int s: bus[x]) {
            i->second = add(i->second, sum(pre, s, x - 1, p), p);
        }
        if(j != pre.begin()) {
            j->second = add(prev(j)->second, i->second, p);
        }
    }
    cout << dp[m] << '\n';
}
