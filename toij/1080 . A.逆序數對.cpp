#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 2e9;
const int N = 2e5+7;

struct Seg{
    int sum;
    int L, R;
} init;

vector<Seg> seg;

int cnt = 2;

void modify(ll k, ll l, ll r, int idx){
    //cout << "Modify " << k << " " << l << " " << r << " " << idx << " " << seg[idx].L << " " << seg[idx].R << '\n';
    if(k<l||k>r)
        return;
    if(l == r){
        seg[idx].sum++;
        return;
    }
    seg[idx].sum++;
    ll m = l+(r-l)/2;
    if(k<=m){
        if(!seg[idx].L){
            seg[idx].L = cnt++;
            seg.push_back(init);
        }
        modify(k, l, m, seg[idx].L);
    }
    else{
        if(!seg[idx].R){
            seg[idx].R = cnt++;
            seg.push_back(init);
        }
        modify(k, m+1, r, seg[idx].R);
    }
}

ll query(ll ql, ll qr, ll l, ll r, int idx){
    if(idx == 0||ql>r||qr<l)
        return 0;
    if(ql<=l&&r<=qr){
        //cout<<l<<' '<<r<<' '<<idx<<' '<<seg[idx].sum<<endl;
        return seg[idx].sum;
    }
    ll m = l+(r-l)/2;
    return query(ql, qr, l, m, seg[idx].L) + query(ql, qr, m+1, r, seg[idx].R);

}

void solve(int n, int c){
    ll a, ans = 0;
    cnt = 2;
    for(int i=0;i<n;i++){
        cin>>a;
        ans += query(a+1, INF, -INF, INF, 1);
        //cout<<query(a+1, INF, 1, INF, 1)<<' ';
        modify(a, -INF, INF, 1);
    }
    // cout<<endl;
    cout << "Case #"<<c<<": "<<ans<<'\n';
}

int main(){
    star;
    int n, c = 0;
    while(cin>>n&&n){
        seg.clear();
        seg.push_back(init);
        seg.push_back(init);
        solve(n, ++c);
    }
}