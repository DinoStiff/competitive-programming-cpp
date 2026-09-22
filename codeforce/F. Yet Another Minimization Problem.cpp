#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define shadow ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = LLONG_MAX;
const int N = 1e5+7;

ll a[N], dp[N], n, m;

struct Cost{
    ll l=0, r=0, ans=0;
    int cnt[N];
    ll cal(int ql, int qr){
        while(r<qr){
            r++;
            ans+=cnt[a[r]];
            cnt[a[r]]++;
        }
        while(r>qr){
            ans-=cnt[a[r]];
            cnt[a[r]]--;
            r--;
        }
        while(l<ql){
            ans-=cnt[a[l]];
            if(a[l])
                cnt[a[l]]--;
            l++;
        }
        while(l>ql){
            l--;
            ans+=cnt[a[l]];
            cnt[a[l]]++;
        }
        return ans;
    }
}cost;

void solve(){
    while()
}

int main(){
    shadow;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        solve();
    }
}