#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9+7;
const int N = 1e5+7;

vector<pii> v[N];
int n, m, d, len;
int f[N];

bool bfs(int k){
    queue<pii> q;
    q.push({1, 0});
    while(q.size()){
        pii x = q.front();
        q.pop();
        if(x.first==n){
            len = x.second;
            return 1;
        }
        if(x.second<d){
            for(auto i:v[x.first]){
                if(i.second<=k&&!f[i.first]){
                    q.push({i.first, x.second+1});
                    f[i.first] = x.first;
                }
            }
        }
    }
    return 0;
}

void ans(int x){
    if(!x)
        return;
    ans(f[x]);
    cout<<x<<' ';
}

int main(){
    star;
    cin>>n>>m>>d;
    int l=0, r = 1;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({b, c});
        r = max(r, c);
    }

    while(l<r){
        int k = (l+r)/2;
        bool ok = bfs(k);
        if(ok)
            r = k;
        else
            l = k+1;
        for(int i=1;i<=n;i++){
            f[i]=0;
        }
    }
    
    if(bfs(l)){
        cout<<len<<'\n';
        ans(n);
    }
    else{
        cout<<"-1\n";
    }
}