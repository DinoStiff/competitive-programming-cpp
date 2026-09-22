#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e8;
const int N = 1e5+7;

bool u[N];

int main(){
    star;
    int n, cur;
    cin>>n>>cur;
    bool a[n];
    ll v[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>v[i];
    }
    cur--;
    ll t=INF, k=1, ans=0;
    while(t--&&cur>=0&&cur<n){
        if(a[cur]==0){
            if(k>=0){
                k+=v[cur];
                k=-k;
            }
            else{
                k-=v[cur];
                k=-k;
            }
        }
        else{
            if(abs(k)>=v[cur]&&u[cur]==0){
                ans++;
                u[cur]=1;
            }
        }
        cur+=k;
    }
    cout<<ans<<'\n';
}