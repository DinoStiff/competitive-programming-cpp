#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    nice;
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans = a[0], tmp = a[0];
    for(int i=1; i<n; i++){
        tmp = max(tmp + a[i], a[i]);
        ans = max(ans, tmp);
    }
    cout<<ans<<'\n';
}