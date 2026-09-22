#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
#define int ll
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

signed main(){
    star;
    //p1 18%
    /*
    int n, a, b, c, d;
    cin>>n;
    cin>>a>>b;
    cin>>c>>d;
    int r = a*c/gcd(a, c);
    for(int i=1;i<=r;i++){
        if(i%a==b&&i%c==d){
            cout<<i<<'\n';
            return 0;
        }
    }
    */
    //p2 19%
    int n;
    cin>>n;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    sort(all(v));
    int a=v[0].first, b=v[0].second;
    for(int i=1;i<n;i++){
        int r = a*v[i].first/gcd(a, v[i].first);
        for(int j=b;j<=r;j+=a){
            if(j%a==b&&j%v[i].first==v[i].second){
                a=r;
                b=j%r;
            }
        }
    }
    if(b)
        cout<<b<<'\n';
    else
        cout<<a<<'\n';
}