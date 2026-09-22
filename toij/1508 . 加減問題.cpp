#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int m, n, a[105], cnt;
bitset <5005> dp;

int main(){
    nice;
    cin >> m >> n;
    while (m--){
        dp.reset();
        cnt = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            cnt += a[i];
        }
        if (cnt&1){
            cout << "No\n";
            continue;
        }
        cnt /= 2;
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = cnt-a[i]; j >= 0; j--){
                if (dp[j]) dp[j+a[i]] = 1;
            }
        }
        if (dp[cnt]) cout << "Yes\n";
        else cout << "No\n";
    }       
}