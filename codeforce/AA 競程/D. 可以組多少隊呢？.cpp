#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    ll n, k, sum = 0;
    cin>>n>>k;
    vector<ll> v(n), ans(k+3);
    for (int i = 0; i < n; i++){
        cin>> v[i];
        sum += v[i];
    }
    sort(v. rbegin(), v.rend());
    int idx = 1;
    for (int i = 0;i < n; i++) {
        while (idx <= k && idx-i > 0 && v[i] <= sum / (idx-i)) {
            ans [idx] = sum / (idx-i);
            idx++;
        }
        sum -= v[i];
    }
    for (int i = 1; i <= k; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}