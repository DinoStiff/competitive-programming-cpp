#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

vector<vector<pii>> v;
set<int> ans;
pii dp[N];

void dfs(int idx, int f){
    dp[idx] = {0, 0};
    set<int> len;
    len.insert(0);
    for(auto [a, b]:v[idx]){
        if(a==f)
            continue;
        dfs(a, idx);
        int ab = dp[a].first+b, as = dp[a].second+b;
        /*
        if(idx == 5){
            cout<<idx<<'\n';
            cout<<ab<<' '<<as<<'\n';
            cout<<a<<' '<<dp[idx].first+ab<<' '<<dp[idx].second+ab<<' '<<dp[idx].first+as<<'\n'<<'\n';
        }
        */
        ans.insert(dp[idx].first+ab);
        ans.insert(dp[idx].second+ab);
        ans.insert(dp[idx].first+as);
        len.insert(ab);
        len.insert(as);
        dp[idx].first = *len.rbegin();
        dp[idx].second = *next(len.rbegin());
    }
}

int main(){
    star;
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n-1;i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(0, -1);
    //cout<<v[5].size()<<'\n';
    /*
    for(int i=0;i<n;i++){
        cout<<dp[i].first<<' '<<dp[i].second<<'\n';
    }
    */
    //cout<<*prev(ans.end())<<endl;
    cout<<*prev(prev(ans.end()))<<endl;
}