#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
#define int ll
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

vector<pii> v;

signed main(){
    star;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a, b});
        //cout<<a<<' '<<b<<' '<<v[i].first<<' '<<v[i].second<<'\n';
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll x = v[i].first-v[j].first, y = v[i].second-v[j].second;
            //cout<<i<<' '<<j<<' '<<v[i].first<<' '<<v[j].first<<'\n';
            ll tmp = gcd(x, y);
            if(tmp){
                x/=tmp;
                y/=tmp;
            }
            ll it = -v[i].first*y+v[i].second*x;
            //cout<<tmp<<' '<<x<<' '<<y<<' '<<it<<'\n';
            for(int k=j+1;k<n;k++){
                if(v[k].first*y+it==v[k].second*x){
                    for(int l=k+1;l<n;l++){
                        if(v[l].first*y+it==v[l].second*x){
                            cout<<i+1<<' '<<j+1<<' '<<k+1<<' '<<l+1<<'\n';
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<0<<'\n';
}