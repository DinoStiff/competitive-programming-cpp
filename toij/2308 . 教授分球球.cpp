#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define strawberry ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
ll ans, sa, sb, a, b;
int main(){
    strawberry;
    int m;
    cin>>m;
    vector<ll> v;
    for(int i=0;i<m;i++){
        ll x;
        cin>>x;
        v.push_back(x);
        if(i&1)
            sb+=x;
        else
            sa+=x;
    }
    if(sa&1||sb&1){
        cout<<0<<'\n';
        return 0;
    }
    sa/=2;
    sb/=2;
    int j=0;
    for(int i=0;i<m;i++){
        while(j<m){
            if(i&1){
                if(b-v[i]>=sb&&a>=sa)
                    break;
            }
            else{
                if(a-v[i]>=sa&&b>=sb)
                    break;
            }
            if(j&1){
                b+=v[j];
                
            }
            else{
                a+=v[j];
            }
            j++;
        }
        if(a>=sa&&b>=sb){
            if(i&1){
                if((j-1)&1&&a==sa){
                    ans+=b-sb+1;
                    if(b-v[i]==sb)
                        ans--;
                }
                else if(b-v[i]<sb&&a-v[j]<=sa)
                    ans++;
            }
            else{
                if(!((j-1)&1)&&b==sb){
                    ans+=a-sa+1;
                    if(a-v[i]==sa)
                        ans--;
                }
                else if(a-v[i]<sa&&b-v[j]<=sb)
                    ans++;
            }
            //if()
        }
        if(i&1)
            b-=v[i];
        else
            a-=v[i];
        cout<<i<<' '<<j-1<<' '<<ans<<' '<<a<<' '<<b<<'\n';
            
    }
    cout<<ans<<'\n';
}