#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    
    for(int j = i;j>0;j=(j-1)&i)
        dp[i] = max(group(j)+dp[i^j]);
}