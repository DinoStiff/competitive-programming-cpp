#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int n;
    cin>>n;
    vector<double> v(n);
    cin>>v[0]>>v[1];
    double ans=(v[0]+v[1])/2, a = v[0]+v[1];
    for(int i=2;i<n;i++){
        cin>>v[i];
        ans = min(ans, min((a+v[i])/3, (a-v[i-2]+v[i])/2));
        a = a - v[i-2]+v[i];
    }
    cout<<ans<<'\n';
}