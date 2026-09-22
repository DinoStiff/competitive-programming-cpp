#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
const int mod = 1e9+7;

int n, m;

vector<vector<int>> path(N);
ll ways[N];
int f[N];

int main(){
    nice;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        path[a].push_back(b);
        f[b]++;
    }
    queue<int> lv;
    for(int i=1;i<=n;i++){
        if(!f[i])
            lv.push(i);
    }
    ways[1]=1;
    while(lv.size()){
        int now = lv.front();
        //cout<<now<<'\n';
        for(int i:path[now]){
            ways[i] = (ways[i] + ways[now]) % mod;
            f[i]--;
            if(!f[i])
                lv.push(i);
        }
        lv.pop();
    }
    cout<<ways[n]<<'\n';
}