#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define minji ios::sync_with_stdio(false);cin.tie(0);
const ll mod = 1000000007;
ll Pow(ll a,ll k){
    ll ans = 1;
    while(k>0){
        if(k&1){
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        k/=2;
        ans%=mod;
    }
    return ans;
}
 
 
int main(){
    minji;
    string s;
    cin>>s;
    int n=s.size();
    s+=s;
    vector<ll>hash(s.size()+1,0);
    vector<ll>p(s.size()+1,0);
    vector<ll>ip(s.size()+1,0);
    for(int i=0;i<2*n+1;i++){
        p[i] = Pow(131,i);
        ip[i] = Pow(p[i],mod-2);
    }
    ll cnt = 0;
    for(int i=0;i<2*n;i++){
        cnt = (cnt+p[i]*(s[i]-'a'+1))%mod;
        hash[i+1] = cnt%mod;
    }
    cnt=1;
    for(int i=2;i<=n;i++){
        int l=0;
        int r = n-1;
        while(l<=r){
            ll mid = (l+r)/2;
            if(((hash[cnt+mid]-hash[cnt-1]+mod)*ip[cnt-1]%mod) == ((hash[i+mid]-hash[i-1]+mod)*ip[i-1])%mod){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(l<=n-1){
            if(s[i+l-1]<s[cnt+l-1])
                cnt = i;
        }
    }
    cout<<s.substr(cnt-1,n);
}