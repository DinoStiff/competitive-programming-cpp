#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

map<int, int> amt;

int main(){
    minji;
    int m, n;
    cin>>m>>n;
    ll ans=0, cnt=0;
    if(n%2==0){
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            a = abs(a);
            amt[a]++;
            if(a==0){
                cnt++;
            }
        }
        if(cnt){
            for(auto i:amt){
                if(!i.first)
                    continue;
                ans+=2*cnt*i.second*i.second;
                //cout<<i.first<<' '<<i.second<<'\n';
            }
            ans+=cnt*cnt*cnt;
        }
        cout<<ans<<'\n';
    }
    else{
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            amt[a]++;
            if(a==0){
                cnt++;
            }
        }
        if(cnt){
            for(auto i:amt){
                if(!i.first)
                    continue;
                ans+=2*cnt*i.second*i.second;
                //cout<<i.first<<' '<<i.second<<'\n';
            }
            for(auto i:amt){
                if(i.first>=0)
                    continue;
                ans+=2*cnt*i.second*amt[-i.first];
                //cout<<i.first<<' '<<i.second<<' '<<amt[-i.first]<<'\n';
                //cout<<i.first<<' '<<i.second<<'\n';
            }
            ans+=cnt*cnt*cnt;
        }
        cout<<ans<<'\n';
    }
    
}