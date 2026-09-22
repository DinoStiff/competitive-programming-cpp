#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define meteor ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;

char c;
ll a; 

pii read(ll k, ll fir){
    ll ans=0, cnt=0, pre;
    while(cin>>c){
        if(c=='L'){
            cin>>k;
            pii res = read(k, pre);
            ans += k*res.first + (k-1) * abs(res.second-a) + abs(res.second - pre);
            if(cnt==0)
                ans-=abs(res.second - pre);
            pre=a;
        }
        else if(c=='T'){
            cin>>a;
            if(cnt==0){
                fir=a;
                cnt++;
            }
            else{
            	ans+=abs(a-pre);
            }
            pre=a;
        }
        else{
        	//cout<<ans<<endl;
            return {ans, fir};
        }
    }
    //cout<<ans<<endl;
    return {ans, fir};
}

int main(){
    meteor;
    cout<<read(1, 10).first<<'\n';
}