#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9+7;
const int N = 2e5+7;

int seg[N*4], h[N], n;

int init(int l, int r, int idx){
    if(l==r)
        return seg[idx] = h[l];
    int m = (l+r)/2;
    return seg[idx] = min(init(l, m, idx*2), init(m+1, r, idx*2+1));
}

void modify(int pos, int k, int l, int r, int idx){
    if(pos<l||pos>r)
        return;
    if(l==r){
        seg[idx]=k;
        return;
    }
    int m = (l+r)/2;
    modify(pos, k, l, m, idx*2);
    modify(pos, k, m+1, r, idx*2+1);
    seg[idx] = min(seg[idx*2], seg[idx*2+1]);
}

int query(int ql, int qr, int l, int r, int idx){
    if(r<ql||qr<l)
        return INF;
    if(ql<=l&&r<=qr)
        return seg[idx];
    int m = (l+r)/2;
    return min(query(ql, qr, l, m, idx*2), query(ql, qr, m+1, r, idx*2+1));
}

int main(){
    star;
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    init(1, n, 1);
    int a, b, c;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            modify(b, c, 1, n, 1);
        }
        else{
            cout<<query(b, c, 1, n, 1)<<'\n';
        }
    }
}