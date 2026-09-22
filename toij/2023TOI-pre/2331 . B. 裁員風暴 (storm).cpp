#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define ll long long
using namespace std;
int n;
ll k, w[200005];
ll INF = 2e9;
bool test(ll x) {
    ll cnt = 0;
    for(int i=1;i<=n;i++){
        if (2*w[i] >= x) cnt++;
    }

    int pos = n;
    for(int i=1;i<n;i++){
        while (pos-1 >= 1 && w[pos-1] + w[i] >= x) pos--;
        if (w[pos] + w[i] >= x) {
            if (pos > i) {
                cnt += n - pos + 1;
            } else {
                cnt += n - i;
            }
        }
    }
    return cnt >= k;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    sort(w+1, w+n+1);
    ll l = -INF-1, r = INF+1;
    ll m;
    while (abs(l-r) > 1) {
        m = (l + r) / 2;
        if (test(m)) l = m;
        else r = m;
    }

    ll ans = l;
    if (ans%2) {
        cout<<ans<<'\n'<<2<<'\n';
    } else {
        cout<<ans/2<<'\n'<<1<<'\n';
    }
}