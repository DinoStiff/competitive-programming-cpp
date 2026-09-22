#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define milk ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

map<int, int> pos;

int main(){
    milk;
    int n, l=0, r=-1, ans=1;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
        pos[v[i]]=-1;
    }
    while(++r<n){
        if(pos[v[r]]>=l)
            l=pos[v[r]]+1;
        pos[v[r]]=r;
        ans=max(ans, r-l+1);
    }
    cout<<ans<<'\n';
}