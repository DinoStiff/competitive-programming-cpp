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
    ll ans=0, x;
    cin>>x;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i*j!=x)
                ans+=i*j;
        }
    }
    cout<<ans<<'\n';
}