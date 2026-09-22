#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 3e5+7;

ll n, b[N], d[N], p[N], x[N], ans[N];

int main(){
    minji;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<n;i++){
        cin>>d[i];
    }
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        p[a]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    b[0]=b[n+1]=INF;
    for(int i=1;i<=n;i++){
        b[p[i]] = min({b[p[i]], b[p[i]-1]+d[p[i]-1], b[p[i]+1]+d[p[i]]});
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    cout<<'\n';
}

