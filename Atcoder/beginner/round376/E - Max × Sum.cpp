#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int t, n, k;
struct pos{
    int a, b;
}c[N];
priority_queue<int,vector<int>,less<int> > pq;
bool cmp(pos a, pos b) {return a.a<b.a;}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>c[i].a;
        for (int i=1;i<=n;i++) cin>>c[i].b;
        sort(c+1,c+1+n,cmp);
        int ans=0,sum=0;
        while (!pq.empty()) pq.pop();
        for (int i=1;i<=k;i++){
            sum+=c[i].b;
            pq.push(c[i].b);
        }
        ans=sum*c[k].a;
        int now=pq.top();
        for (int i=k+1;i<=n;i++){
            if (c[i].b<now) sum=sum-now+c[i].b,pq.pop(),pq.push(c[i].b),now=pq.top();
            ans=min(ans,sum*c[i].a);
        }
        cout<<ans<<'\n';
    }
}