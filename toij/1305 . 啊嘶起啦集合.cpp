#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 2e9;
const int N = 2e5+7;

struct Seg{
    ll sum;
    int L, R;
} init;

vector<Seg> seg;

int cnt = 2;

bool add(ll k, ll l, ll r, int idx){
    bool ext = 0;
    //cout << "add " << k << " " << l << " " << r << " " << idx << " " << seg[idx].L << " " << seg[idx].R << '\n';
    if(k<l||k>r)
        return;
    if(l == r){
        if(seg[idx].sum)
            ext = 1;
        seg[idx].sum = 1;
        return ext;
    }
    seg[idx].sum ++;
    ll m = l+(r-l)/2;
    if(k<=m){
        if(!seg[idx].L){
            seg[idx].L = cnt++;
            seg.push_back(init);
            
        }
        ext = add(k, l, m, seg[idx].L);
    }
    else{
        if(!seg[idx].R){
            seg[idx].R = cnt++;
            seg.push_back(init);
        }
        ext = add(k, m+1, r, seg[idx].R);
    }
    seg[idx].sum -= ext;
}

bool del(ll k, ll l, ll r, int idx){
    bool ext = 0;
    //cout << "add " << k << " " << l << " " << r << " " << idx << " " << seg[idx].L << " " << seg[idx].R << '\n';
    if(k<l||k>r)
        return;
    if(l == r){
        if(!seg[idx].sum)
            ext = 1;
        seg[idx].sum = 0;
        return ext;
    }
    seg[idx].sum --;
    ll m = l+(r-l)/2;
    if(k<=m){
        if(!seg[idx].L){
            seg[idx].L = cnt++;
            seg.push_back(init);
            
        }
        ext = del(k, l, m, seg[idx].L);
    }
    else{
        if(!seg[idx].R){
            seg[idx].R = cnt++;
            seg.push_back(init);
        }
        ext = del(k, m+1, r, seg[idx].R);
    }
    seg[idx].sum += ext;
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

void solve(ll k, ll l, ll r, int idx){
    ll a, ans = 0;
    cnt = 2;
    for(int i=0;i<n;i++){
        cin>>a;
        ans += query(a+1, INF, -INF, INF, 1);
        //cout<<query(a+1, INF, 1, INF, 1)<<' ';
        add(a, -INF, INF, 1);
    }
    // cout<<endl;
    cout << "Case #"<<c<<": "<<ans<<'\n';
}

int main(){
    star;
    int n, x;
    string c;
    while(cin>>c&&c!="exit"){
        cin>>x;
        if(c == "insert"){
            add(x, -INF, INF, 1);
        }
        else if (c == "remove"){
            del(x, -INF, INF, 1);
        }
        else{
            solve(x, -INF, INF, 1);
        }
    }
}