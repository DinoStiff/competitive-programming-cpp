#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define alcohol ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

map<int, bool> m[N];
vector<int> v[N];
int n, ans[N];

void dfs(int idx, int p){
    int k=0;
    for(int i:v[idx]){
        if(i!=p){
            dfs(i, idx);
            if(m[i].size()>m[k].size()){
                k=i;
            }
        }
    }
    swap(m[idx], m[k]);
    for(int i:v[idx]){
        if(i!=p){
            for(auto [j, cnt]:m[i]){
                m[idx][j] |= cnt;
                cout<<idx<<' '<<i<<' '<<j<<' '<<cnt<<endl;
            }
        }
    }
    ans[idx] = m[idx].size();
}

int main(){
    alcohol;
    cin>>n;
    int a, b;
    for(int i=1;i<=n;i++){
        cin>>a;
        m[i][a]|=1;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}