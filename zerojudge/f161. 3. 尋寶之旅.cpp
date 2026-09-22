//吃毒解
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define umii unordered_map<int, int>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int c[N], n, ans=0;
vector<int> v[N];
umii um[N];

void merge(umii &x, umii &y){
    // if(x.size()<y.size());
    //     swap(x, y);
    for(auto &[i,j]:y){
        x[i]=max(x[i], j);
    }
}

void dfs(int idx){
    int tmp=idx;
    for(int &i:v[idx]){
        dfs(i);
        if(um[tmp].size()<um[i].size())
            tmp=i;
    }
    if (idx == tmp) {
        um[idx][c[idx]]++;
        return;
    }
    swap(um[idx], um[tmp]);
    // merge(um[idx], um[tmp]);
    for(int &i:v[idx]){
        if(i!=tmp)
            merge(um[idx], um[i]);
    }
    um[idx][c[idx]]++;
}

int main(){
    star;
    cin>>n;
    // v.resize(n+5);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    dfs(0);
    for(auto [i, j]:um[0]){
        ans=max(ans, j);
    }
    cout<<ans<<'\n';
}