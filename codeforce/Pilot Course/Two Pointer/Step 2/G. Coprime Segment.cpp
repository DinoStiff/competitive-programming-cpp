#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

ll seg[4*N], a[N], n;

ll init(int l, int r, int idx){
    if(l==r){
        return seg[idx] = a[l];
    }
    int m=(l+r)/2;
    return seg[idx] = gcd(init(l, m, idx*2), init(m+1, r, idx*2+1));
}

ll query(int ql, int qr, int l, int r, int idx){
    if(ql<=l&&r<=qr)
        return seg[idx];
    int m = (l+r)/2;
    if(m<ql)
        return query(ql, qr, m+1, r, idx*2+1);
    if(m>=qr)
        return query(ql, qr, l, m, idx*2);
    return gcd(query(ql, qr, l, m, idx*2), query(ql, qr, m+1, r, idx*2+1));
}

int main(){
    star;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    init(1, n, 1);

    int r = 1, ans = N;
    for(int l=1;l<=n;l++){
        ll cnt;

        if(r<l) r=l;

        while(r<=n&&query(l, r, 1, n, 1)>1){
            r++;
        }
        if(r<=n)
            ans=min(ans, r-l+1);
    }

    if(ans==N)
        cout<<"-1\n";
    else
        cout<<ans<<'\n';
}