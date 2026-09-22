//55%
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const ll INF = 1e17;
const int N = 2e5+7;
int n, a[N], b[N], w[N], dp[N], nxt[N];

int main(){
    cin>>n;
    map<int, int> pos, re;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        pos[a]=i;
    }
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        pos[a]=i;
    }
    
}