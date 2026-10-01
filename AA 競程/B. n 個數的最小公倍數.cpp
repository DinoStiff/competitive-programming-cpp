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
    __int128 ans = 1;
    while(n--){
        ll a, tmp;
        cin>>a;
        tmp = gcd(ans, a);
        ans = ans/tmp * a;
        if(ans > 1e18){
            cout<<"The answer is too large.\n";
            return 0;
        }
    }
    cout<<(ll)ans<<'\n';
}