#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define int ll
#define milk ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, dp[5000];
vector<int> lf;
vector<pii> rt;

int solve(){
    lf.clear();
    rt.clear();
    memset(dp, 0, sizeof dp);
    cin>>n;
    int a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(b==1){
            lf.push_back(a);
        }
        else{
           rt.push_back({a, b}); 
        }
    }
    if(rt.empty()){
        if(lf.size()>2)
            return -1;
        else
            return abs(lf[1]-lf[0]);
    }
    sort(all(rt));
    rt[0].second--;
    if(rt.size()>1)
        rt.back().second--;
    for(int i=1;i<rt.size()-1){
        rt[i].second-=2;
    }
    for(int i=0;i<rt.size();i++){
        
    }
}

signed main(){
    milk;
    int T;
    cin>>T;
    while(T--){
        int ans = solve();
        cout<<ans<<'\n';
    }
}