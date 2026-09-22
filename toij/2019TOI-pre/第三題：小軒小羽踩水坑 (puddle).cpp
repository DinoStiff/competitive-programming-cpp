#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
#define int ll
using namespace std;

const ll INF = 1e17;
const int N = 1e6+7;

ll Hash(ll x, ll y) {
    return x*1000+y;
}

int n, m, k;
ll p[N], ans=0, amt=0, sans=0, samt=0;
bool w[207][507];

int findp(int k){
    return p[k]>0? p[k]=findp(p[k]):k;
}

void merge(int a, int b){
    int x=findp(a), y=findp(b);
    if(x==y)
        return;
    if(p[x]>p[y])
        swap(x, y);
    p[x]+=p[y];
    p[y]=x;
    ans=max(ans, -p[x]);
    amt--;
}

signed main(){
    star;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>w[i][j];
            w[i][j]^=1;
            if(w[i][j]){
                p[Hash(i, j)]=-1;
                amt++;
                ans=max(ans, 1LL);
                if(w[i-1][j]){
                    merge(Hash(i, j), Hash(i-1, j));
                }
                if(w[i][j-1]){
                    int x = Hash(i, j);
                    int y = Hash(i, j-1);
                    //cout<<x<<' '<<y<<' '<<p[findp(x)]<<' '<<p[findp(y)]<<'\n'; 
                    merge(x, y);
                }
                //cout<<amt<<'\n'<<ans<<'\n';
            }
        }
    }
    sans=ans;
    samt=amt;
    int x, y;
    while(k--){
        int cnt=0;
        cin>>y>>x;
        p[Hash(y, x)]=-1;
        ans=max(ans, 1LL);
        amt++;
        w[y][x]=1;
        if(w[y-1][x]){
            merge(Hash(y, x), Hash(y-1, x));
            cnt++;
        }
        if(w[y+1][x]){
            merge(Hash(y, x), Hash(y+1, x));
            cnt++;
        }
        if(w[y][x-1]){
            merge(Hash(y, x), Hash(y, x-1));
            cnt++;
        }
        if(w[y][x+1]){
            merge(Hash(y, x), Hash(y, x+1));
            cnt++;
        }
        //cout<<amt<<' '<<ans<<'\n';
        sans+=ans;
        samt+=amt;
    }
    cout<<samt<<'\n'<<sans<<'\n';
}