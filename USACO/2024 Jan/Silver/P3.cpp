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
    int n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    n = v.size();
    ll d = v[0]/4, ans = 6;
    if(d==1){
        cout<<"1\n";
    }
    else if(d==2){
        cout<<"3\n";
    }
    else if(d==3){
        cout<<"6\n";
    }
    else{
        for(ll i = 4;i<=d;i++){
            set<ll> s;
            bool ok = 1;
            for(int j=0;j<n;j++){
                s.insert(v[j]%i);
                if(s.size()>=4){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ans+=i;
            }
        }
    }
    cout<<ans<<'\n';
}