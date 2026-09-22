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
    ll x, y;
    cin>>x>>y;
    x = abs(x);
    y = abs(y);
    if(x==0&&y==0){
        cout<<0<<'\n';
    }
    else if(y==0||x%y!=0)
        cout<<"0AQ\n";
    else
        cout<<abs(x/y)<<'\n';
}