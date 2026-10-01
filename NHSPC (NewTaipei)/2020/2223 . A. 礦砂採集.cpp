#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define N 1005
using namespace std;
using pii = pair<int,int>;
int n,m;
pii in[N];

int main()
{
    cin>>n>>m;
    REP(i,1,n) cin>>in[i].second>>in[i].first;
    sort(in+1, in+n+1, greater<pii> ());

    int ans = 0;
    REP(i,1,n) {
        int w = min(in[i].second, m);
        ans += w * in[i].first;
        m -= w;
    }
    cout<<ans<<'\n';
    return 0;
}
