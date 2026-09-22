#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

ll h[N], m[N];
int ord[N];

ll solve(int n){
    ll l=-1, r = INF;
    for(int k=0;k<n-1;k++){
        int i = ord[k], j = ord[k+1];
        ll cnt;
        if(m[i]>m[j]){
            cnt = (h[j]-h[i])/(m[i]-m[j]);
            if((h[j]-h[i])<0)
                cnt--;
            l = max(l, cnt+1);
        }
        else if(m[i]<m[j]){
            cnt = (h[j]-h[i])/(m[i]-m[j]) + (bool)((h[j]-h[i])%(m[i]-m[j]));
            if((h[j]-h[i])>0)
                cnt--;
            r = min(r,  cnt-1);
        }
        else{
            if(h[i]<=h[j])
                return -1;
        }
    }
    if(l<=r&&r>=0)
        return max(0LL, l);
    return -1;
}

int main(){
    star;
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        for(int i=0;i<n;i++){
            cin>>m[i];
        }
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            ord[a]=i;
        }
        cout<<solve(n)<<'\n';
    }
}