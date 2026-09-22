#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

struct Seg{
    ll sml, big;
    ll ans(){
        return big-sml;
    }
}seg[4*N];

Seg merge(Seg a, Seg b){
    return {min(a.sml, b.sml), max(a.big, b.big)};
}

ll a[N], n, s;

Seg init(int l, int r, int idx){
    if(l==r){
        return seg[idx] = {a[l], a[l]};
    }
    int m=(l+r)/2;
    return seg[idx] = merge(init(l, m, idx*2), init(m+1, r, idx*2+1));
}

Seg query(int ql, int qr, int l, int r, int idx){
    if(ql<=l&&r<=qr)
        return seg[idx];
    int m = (l+r)/2;
    if(m<ql)
        return query(ql, qr, m+1, r, idx*2+1);
    if(m>=qr)
        return query(ql, qr, l, m, idx*2);
    return merge(query(ql, qr, l, m, idx*2), query(ql, qr, m+1, r, idx*2+1));
}

int main(){
    star;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    init(1, n, 1);

    ll r = 1, ans = 0;
    for(int l=1;l<=n;l++){
        ll cnt;
        if(r<l) r=l;
        while(r<=n&&query(l, r, 1, n, 1).ans()<=s){
            r++;
            ans+=r-l;
        }
    }
    cout<<ans<<'\n';
}