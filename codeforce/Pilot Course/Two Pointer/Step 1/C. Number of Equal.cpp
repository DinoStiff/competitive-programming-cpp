#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
map<int,int> mp;
int main(){
    star;
    int n, m;
    ll ans=0;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    } 

    int i = 0;
    for (int j = 0; j < m; j++) {
        if (mp.find(b[j]) == mp.end()) {
            while (i < n && a[i] < b[j]) i++;
            int tmp = 0;
            while (i < n && a[i] == b[j]) {
                i++, tmp++;
            }
            mp[b[j]] = tmp;
            ans += tmp;
        } else {
            ans += mp[b[j]];
        }
    }

    cout << ans << endl;
}