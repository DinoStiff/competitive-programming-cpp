#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

ll n, a[N], dp[N], pre[N];

bool check(ll k){
    deque<pii> dq;
    dq.push_back({0, 0});
    for(int i=1;i<=n;i++){
        ll tmp = pre[i-1] - k;
        while(pre[dq.front().second]<tmp)
            dq.pop_front();
        dp[i] = dq.front().first + a[i];
        while(dq.size()&&dq.back().first>=dp[i])
            dq.pop_back();
        dq.push_back({dp[i], i});
    }
    int i = n;
    ll res = INF;
    while(i>=0&&pre[n]-pre[i]<=k){
        res = min(res, dp[i]);
        i--;
    }
    return res<=k;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    ll l = 1, r = pre[n];
    while(l<r){
        ll k = (l+r)/2;
        if(check(k))
            r = k;
        else
            l = k+1;
    }
    cout<<l<<'\n';
}

int main(){
    star;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}