#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

ll cow[N], candy[N];

int main(){
    star;
    ll n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>cow[i];
    }
    for(int i=0;i<m;i++){
        cin>>candy[i];
    }
    for(int i=0;i<m;i++){
        ll h = 0, idx = 0;
        while(h<candy[i]&&idx<n){
            if(cow[idx]>h){
                ll tmp = cow[idx];
                cow[idx]+=(min(cow[idx], candy[i]) - h);
                h = tmp;
            }
            idx++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<cow[i]<<'\n';
    }
}