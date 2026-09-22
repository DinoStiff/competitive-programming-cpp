#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int n;
    cin>>n;
    int pos[n], p[n], l[n], r[n], h[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        pos[p[i]-1]=i;
    }
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    h[pos[n-1]]=r[pos[n-1]];
    for(int i=n-2;i>=0;i--){
        int idx = pos[i];
        if(l[idx]>h[pos[i+1]]){
            cout<<"No\n";
            return 0;
        }
        h[idx] = min(r[idx], h[pos[i+1]]);
    }
    cout<<"Yes\n";
    for(int i=0;i<n;i++){
        cout<<p[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<h[i]<<' ';
    }
    cout<<'\n';
}