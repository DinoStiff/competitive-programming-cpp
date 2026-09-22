#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1000;
long long n, k, x, cnt[1005], ans;
int main(){  
    minji;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> x;
        ++cnt[x];
        for(int j = x*k + 1; j <= N; ++j)
            ans += cnt[j];
    }
    cout << ans << "\n";
}