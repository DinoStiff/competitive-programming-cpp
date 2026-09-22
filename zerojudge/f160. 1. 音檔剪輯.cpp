#include <bits/stdc++.h>
using namespace std;
 
int m, n, a, dp[10005];
vector <int> v;
 
int main() {
    cin >> m >> n;
    v.push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> a;
        v.push_back(a);
        dp[i] = dp[lower_bound(v.begin(), v.end(), a-m)-v.begin()]+1;
    }
    cout << dp[n] << "\n";
}