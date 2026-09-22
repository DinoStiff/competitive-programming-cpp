#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e5+7;

int n;

vector<vector<int>> v(N);
int c[N], used[N];
set<int> ans;

void dfs(int x, int f){
    if(!used[c[x]])
        ans.insert(x);
     used[c[x]]++;
    for(int i:v[x]){
        if(i!=f)
            dfs(i, x);
    }
    used[c[x]]--;
}

int main(){
    nice;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int a, b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    for(int i:ans){
        cout<<i<<'\n';
    }
}