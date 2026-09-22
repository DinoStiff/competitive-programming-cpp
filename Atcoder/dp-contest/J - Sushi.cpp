#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 3e2+7;

int n, cnt[4];
double dp[N][N][N];

double dfs(int i, int j, int k) {
    double &ans = dp[i][j][k];
    if (ans > 0) return ans;
    if (!i && !j && !k) return 0;
    if (i) ans += dfs(i - 1, j, k) * i ;
    if (j) ans += dfs(i + 1, j - 1, k) * j;
    if (k) ans += dfs(i, j + 1, k - 1) * k;
    ans = (ans + n) / (i + j + k);
    return ans;
}

int main(){
    star;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    cout << fixed << setprecision(10) << dfs(cnt[1], cnt[2], cnt[3]) << '\n';
}