#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18+7;
const int N = 2e5+7, C = 1e9+2;

struct Tree{
    ll slp = 0, y_int = INF;
    Tree *L = nullptr, *R = nullptr;
    ll operator () (ll x){
        return slp*x+y_int;
    }
}root;


void modify(ll m, ll k, ll ql, ll qr, ll l, ll r, Tree *seg){
    if(qr<l||ql>r){
        return;
    }
    ll mid = (l + r)/2;
    
    if (qr<=mid){
        if(seg->L==nullptr)
            seg->L = new Tree;
        modify(m, k, ql, qr, l, mid, seg->L);
    }
    else if(mid<ql){
        if(seg->R==nullptr)
            seg->R = new Tree;
        modify(m, k, ql, qr, mid+1, r, seg->R);
    }
    else if(ql <= l && qr >= r){
        if(m*mid+k<(*seg)(mid)){
            swap(seg->slp, m);
            swap(seg->y_int, k);
        }
        if(l==r)
            return;
        if(m>seg->slp){
            if(seg->L==nullptr)
                seg->L = new Tree;
            modify(m, k, ql, qr, l, mid, seg->L);
        }
        else{
            if(seg->R==nullptr)
                seg->R = new Tree;
            modify(m, k, ql, qr, mid+1, r, seg->R);
        }
    }
    else{
        if(seg->L==nullptr)
                seg->L = new Tree;
        modify(m, k, ql, qr, l, mid, seg->L);
        if(seg->R==nullptr)
                seg->R = new Tree;
        modify(m, k, ql, qr, mid+1, r, seg->R);
    }
}

ll query(ll k, ll l, ll r, Tree *seg){
    ll res=INF;
    if(k<l||k>r)
        return INF;
    if(l==r){
        return (*seg)(k);
    }
    ll mid = (r+l)/2;
    if(k<=mid){
        if(seg->L!=nullptr)
            res = query(k, l, mid, seg->L);
        return min((*seg)(k), res);
    }
    else{
        if(seg->R!=nullptr)
            res = query(k, mid+1, r, seg->R);
        return min((*seg)(k), res);
    }
}

int main(){
    star;
    ll n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        modify(c, d, a, b, -C, C, &root);
    }
    for(int i=1;i<=q;i++){
        ll a, b, c, d, e;
        cin>>a;
        if(a==0){
            cin>>b>>c>>d>>e;
            modify(d, e, b, c, -C, C, &root);
        }
        else{
            cin>>b;
            cout<<query(b, -C, C, &root)<<'\n';
        }
    }
}