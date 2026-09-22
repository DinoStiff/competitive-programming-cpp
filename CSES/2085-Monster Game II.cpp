#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7, C = 1e6;

ll dp[N], s[N], f[N];

struct Tree{
    ll slp, y_int;

    ll operator () (int x){
        return slp*x+y_int;
    }
}seg[4*C+7];

void init(){
    for(int i=1;i<=4*C;i++){
        seg[i]={0, INF};
    }
}

void modify(ll m, ll k, int l, int r, int idx){
    ll mid = (l+r)/2;
    if(m*mid+k<seg[idx](mid)){
        swap(seg[idx].slp, m);
        swap(seg[idx].y_int, k);
    }
    if(l==r)
        return;
    if(m>seg[idx].slp)
        modify(m, k, l, mid, idx*2);
    else
        modify(m, k, mid+1, r, idx*2+1);
}

ll query(ll k, int l, int r, int idx){
    if(k<l||k>r)
        return INF;
    if(l==r){
        return seg[idx](k);
    }
    int mid = (l+r)/2;
    if(k<=mid)
        return min(seg[idx](k), query(k, l, mid, idx*2));
    else
        return min(seg[idx](k), query(k, mid+1, r, idx*2+1));
}

int main(){
    star;
    ll n;
    init();
    cin>>n>>f[0];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    modify(f[0], 0, 1, C, 1);
    for(int i=1;i<=n;i++){
        dp[i] = query(s[i], 1, C, 1);
        modify(f[i], dp[i], 1, C, 1);
    }
    cout<<dp[n]<<'\n';
}