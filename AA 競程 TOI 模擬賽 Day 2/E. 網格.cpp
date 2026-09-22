#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll a[N], n, m, k;

bool solve(ll dis, vector<pii> v){
    ll cnt = 0;
    for(auto [i, j]:v){
        if(j==0){
            cnt+=max(0LL, a[j+1]-dis-a[j]);
        }
        else if(j==m-1){
            cnt+=max(0LL, a[j-1]-dis-a[j]);
        }
        else{
            cnt+=max(0LL, a[j+1]-dis-a[j]);
            cnt+=max(0LL, a[j-1]-dis-a[j]);
        }
        //cout<<cnt<<'\n';
        if(cnt>k){
            return 0;
        }
    }
    //cout<<"efwef\n";
    return 1;
}

int main(){
    minji;
    ll l=0, r=0;
    cin>>n>>m>>k;
    vector<pii> v;
    for(int i=0;i<n;i++){
        cin>>a[0];
        v.push_back({a[0], 0});
        for(int j=1;j<m;j++){
            cin>>a[j];
            r = max(r, abs(a[j]-a[j-1]));
            v.push_back({a[j], j});
        }
    }
    sort(all(v));
    n=2;
    while(n--){
        ll mid = (l+r)/2;
        //cout<<l<<' '<<r<<' '<<mid<<'\n';
        bool ok = solve(mid, v);
        if(ok){
            r = mid;
        }
        else{
            l = mid+1;
        }
        
    }
    cout<<l<<'\n';
}