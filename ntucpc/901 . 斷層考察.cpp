#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 5e5+20;

ll arr[N];

int main(){
    minji;
    int n, q;
    cin>>n>>q;
    while(q--){
        ll o;
        cin>>o;
        if(o==1){
            ll a, b;
            cin>>a>>b;
            for(ll i=1;i<=n;i++){
                arr[i]=max(arr[i], a*i+b);
            }
        }
        else if(o==2){
            ll a;
            cin>>a;
            for(ll i=1;i<=n;i++){
                arr[i]=min(arr[i], a);
            }
        }
        else{
            ll a=-INF, l, r;
            cin>>l>>r;
            for(ll i=l;i<=r;i++){
                a=max(a, arr[i]);
            }
            cout<<a<<'\n';
        }
    }
}