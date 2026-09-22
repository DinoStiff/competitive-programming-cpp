#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    ll n, m, k;
    cin >> n >> m;
    k=m;
    ll ans[n+1];
    vector<pii> l;
    vector<pair<double, int>> v;
    
    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        l.push_back({x, i+1});
    }
    for (int i = 0; i < m; i++){
        int x;
        cin>>x;
        v.push_back({x, i+1});
    }
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(v[i].first-x<=0){
            k--;
        }
        v[i].first=1./(x+v[i].first)+1./(v[i].first-x);

    }
    if(k<n){
        cout<<-1<<'\n';
        return 0;
    }
    sort(rall(l));
    sort(all(v));
    for(int i=0;i<n;i++){
        ans[l[i].second]=v[i].second;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
