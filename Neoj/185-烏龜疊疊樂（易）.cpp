#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define N 500005
#define strawberry ios::sync_with_stdio(false);cin.tie(0)
using namespace std;
int n, k, arr[N], pre[N];

signed main(){
    strawberry;
    cin>>n>>k;
    for(int i=n;i>0;i--)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
        pre[i] = pre[i-1]+arr[i];
    
    int dp[N];
    memset(dp, 0, sizeof(dp));
    
    deque<pii> dq;
    dq.push_back({0, 0});
    
    for(int i=1;i<=n;i++){
        while(dq.size() && dq.front().second < i-k)
            dq.pop_front();
        dp[i] = dq.front().first;
        while(dq.size() && dq.back().first <= dp[i]+pre[i])
            dq.pop_back();
        dq.push_back({dp[i]+pre[i], i});
    }
    cout<<dp[n]<<endl;
}