#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
const ll mod = 1000000007;
vector<int> v[N];
ll dp[N][2];

void recurse(int x, int p)
{
    for (int i : v[x]) {
        if (i == p) continue;
        recurse(i, x);
        dp[x][1] = (((dp[x][1] * dp[i][0]) % mod + (dp[x][0] * dp[i][1]) % mod) + dp[x][1] * dp[i][1]) % mod;
        dp[x][1] = dp[x][1] % mod;

        dp[x][0] = ((dp[x][0] * dp[i][0]) % mod + (dp[x][0] * dp[i][1]) % mod) % mod;
        dp[x][0] = dp[x][0] % mod;
    }
}

int main(){
    minji;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        v[i + 1].push_back(x);
        v[x].push_back(i + 1);
    }
    vector<bool> inp(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inp[i] = (x == 1);
        if (inp[i]) {
            dp[i][1] = 1ll;
        } else {
            dp[i][0] = 1ll;
        }
    }
    recurse(0, -1);
    cout << dp[0][1] << endl;
    return 0;
}
