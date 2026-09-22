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
    ll n, x;
    cin>>n;
    while(n--){
        cin>>x;
        if(1<=x&&x<=7){
            cout<<2*x-1<<'\n';
            continue;
        }
        ll l = 1, r = (x+1)*x/2;
        while(l<r){
            ll m = (l+r)/2, cnt=0, ok=0;
            for(ll i = x;i>=1;i--){
                if(cnt+i<=m)
                    cnt+=i;
                else{
                    //cout<<i<<' '<<cnt<<' '<<ok<<' ';
                    ok++;
                    cnt=2*i+1;
                    if(ok==3)
                        cnt+=x;
                    //cout<<cnt<<'\n';
                }
            }
            //cout<<m<<' '<<ok<<"\n\n";
            if(ok<=3)
                r=m;
            else
                l=m+1;
        }
        cout<<r<<"\n";
    }
}