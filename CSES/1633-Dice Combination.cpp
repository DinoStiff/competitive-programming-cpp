#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 1000001
#define mod 1000000007

int dp[N], n;

int f (int l) {
    if (dp[l] != 0) {
        return dp[l];
    }
    for (int i = 1; i <= 6; i++) {
        if (l - i >= 0) {
            dp[l] += f(l - i);
            dp[l] %= mod;
        }
    }
    return dp[l];
}

int main() {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    cout << f(n) << endl;
}