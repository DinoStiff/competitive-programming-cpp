#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = LLONG_MAX;
const int N = 2e5+7;

int n, m;

struct pos{
    ll x, y, r, id, dis=INF;
    bool operator < (const pos& b)const{
        if(dis==b.dis){
            if(r==b.r)
                return id<b.id;
            return r<b.r;
        }
        return dis<b.dis;
    }
};

vector<pii> st;

int main(){
    star;
    cin>>n>>m;
    ll x, y, r;
    vector<pos> h;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>r;
        h.push_back({x, y, r, i});
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        st.push_back({x, y});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            h[i].dis=min(h[i].dis, (ll)(h[i].x-st[j].first)*(h[i].x-st[j].first)+(ll)(h[i].y-st[j].second)*(h[i].y-st[j].second));
        }
    }
    sort(h.begin(), h.end());
    for(auto i:h){
        cout<<i.id<<'\n';
    }
}