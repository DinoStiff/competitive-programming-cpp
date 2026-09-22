#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k & 1 || k > n * 2 + 2){
        cout<<"No\n";
        return;
    }
    int a = sqrt(n);
    if((a + (n + a - 1) / a) * 2 > k){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
}

int main() {
    minji;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}