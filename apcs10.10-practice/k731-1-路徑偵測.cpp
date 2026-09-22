#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)

const ll INF = 1e17;

ll n, m;

using namespace std;
int main(){
  star;
  cin>>n;
  ll a, b, x=0, y=0, d=3;
  ll l=0, r=0, t=0;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    a-=x;
    b-=y;
    x+=a;
    y+=b;
    if(d==1){
        if(b>0){
            r++;
            d=2;
        }
        if(b<0){
            l++;
            d=4;
        }
        if(a>0){
            t++;
            d=3;
        }
    }
    if(d==2){
        if(a>0){
            r++;
            d=3;
        }
        if(a<0){
            l++;
            d=1;
        }
        if(b<0){
            t++;
            d=4;
        }
    }
    if(d==3){
        if(b>0){
            l++;
            d=2;
        }
        if(b<0){
            r++;
            d=4;
        }
        if(a<0){
            t++;
            d=1;
        }
    }
    if(d==4){
        if(a>0){
            l++;
            d=3;
        }
        if(a<0){
            r++;
            d=1;
        }
        if(b>0){
            t++;
            d=2;
        }
    }
    //cout<<x<<' '<<y<<' '<<l<<' '<<r<<' '<<t<<endl;
  }
  cout<<l<<' '<<r<<' '<<t<<endl;
}