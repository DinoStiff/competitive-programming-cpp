#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e7;
const int N = 1e6+7;

int seg[N*4], h[N], n;

int init(int l, int r, int idx){
    if(l==r)
        return seg[idx] = h[l];
    int m = (l+r)/2;
    return seg[idx] = min(init(l, m, idx*2), init(m+1, r, idx*2+1));
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
    minji;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    init(1, n, 1);
    int t = n, l, r;
    while(t--){
        cin>>l>>r;
        cout<<query(l, r, 1, n, 1)+1<<'\n';
    }
}