#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll n, a[105][105], ans, sum;

int main(){
    minji;
    while (cin >> n){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
                a[i][j] += a[i][j-1];
            }
        }
        ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j <= n; j++){
                sum = 0;
                for (int k = 1; k <= n; k++){
                    sum += a[k][j]-a[k][i];
                    ans = max(ans, sum);
                    if (sum < 0) sum = 0;
                }
            }
        }
        cout << ans << "\n";
    }
}