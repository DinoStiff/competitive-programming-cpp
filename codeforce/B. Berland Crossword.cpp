#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

void solve(){
    int n, a, b, c, dd;
    cin>>n>>a>>b>>c>>dd;
 
    for (int i = 0; i<16; i++){
        bool ok = true;
 
        int u = 0, d = 0, r = 0, l = 0;
        if (i&1){
            u++;
            l++;
        }
        if (i&2){
            l++;
            d++;
        }
        if (i&4){
            d++;
            r++;
        }
        if (i&8){
            r++;
            u++;
        }
        if (u>a || u + (n-2)<a) ok = false;
        if (d>c || d + (n-2)<c) ok = false;
        if (l>dd || l + (n-2)<dd) ok = false;
        if (r>b || r + (n-2)<b) ok = false;
 
        if (ok) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
 
}
int main() {
    minji;
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}