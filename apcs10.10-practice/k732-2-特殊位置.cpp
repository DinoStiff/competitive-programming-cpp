#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)

const ll INF = 1e17;

ll n, m;

ll dis(ll x1, ll y1, ll x2, ll y2){
    return abs(x1-x2) + abs(y1-y2);
}

using namespace std;
int main(){
    star;
    cin>>n>>m;
    ll a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    ll k, ans=0, sum;
    vector<pii> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            k = a[i][j];
            sum=0;
            for(int y=0;y<n;y++){
                for(int x=0;x<m;x++){
                    if(dis(j, i, x, y)<=k){
                        sum+=a[y][x];
                    }
                }
            }
            if(sum%10==k){
                ans++;
                v.push_back({i, j});
            }
        }
    }
    cout<<ans<<'\n';
    for(auto i:v){
        cout<<i.first<<' '<<i.second<<'\n';
    }
}