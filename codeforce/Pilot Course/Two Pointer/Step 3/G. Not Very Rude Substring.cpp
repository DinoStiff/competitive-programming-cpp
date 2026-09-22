#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    ll n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    ll r=0, ans=0; 
    ll a=0, b=0, sum=0;
    for(int l=0;l<n;l++){
        while(r<n&&sum<=c){
            if(s[r]=='b'){
                b++;
                sum+=a;
            }
            if(s[r]=='a')
                a++;
            if(sum<=c)
                ans=max(ans, r-l+1);
            //cout<<l<<" "<<r<<" "<<sum<<" "<<ans<<endl;
            r++;
        }
        if(s[l]=='a'){
            a--;
            sum-=b;
        }
        if(s[l]=='b')
            b--;
    }
    cout<<ans<<'\n';
}