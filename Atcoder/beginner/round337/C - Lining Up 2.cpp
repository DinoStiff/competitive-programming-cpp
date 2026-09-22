#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 3e5+7;

int main(){
    star;
    int n, a;
    cin>>n;
    int v[n+1];
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a==-1){
            a=0;
        }
        v[a]=i;
    }
    int x = 0;
    for(int i=0;i<n;i++){
        cout<<v[x]<<' ';
        x = v[x];
    }
    cout<<'\n';
}