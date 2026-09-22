#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

vector<vector<int>> v, dp;

void dfs(int x, int p) {
    dp[x][0] = 0;
    dp[x][1] = 1;
    for (int i : v[x]) {
        if (i == p){
            continue;
        }
        dfs(i, x);
        dp[x][0] += dp[i][1];
        dp[x][1] += min(dp[i][0], dp[i][1]);
    }
}

int main(){
    int n;
    while (cin >> n && n) {
        v.clear();
        v.resize(n+1);
        dp.clear();
        dp.resize(n+1, vector<int>(2, 0));
        for (int i=0; i<n; i++) {
            int a, k, b;
            scanf("%d:(%d)", &a, &k);
            for (int j=0; j<k; j++) {
                cin >> b;
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
        dfs(0, -1);
        cout << min(dp[0][0], dp[0][1]) << '\n';
    }
}

