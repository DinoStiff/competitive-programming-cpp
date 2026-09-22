#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

bool cmp(pii a, pii b){
    if(a.second<b.second)
        return 1;
    if(a.second==b.second)
        return a.first<b.first;
    return 0;
}

int main(){
    minji;
    int n;
    cin>>n;
    vector<pii> v(n);
    for(auto &[i, j]:v){
        cin>>i;
    }
    for(auto &[i, j]:v){
        cin>>j;
    }
    
    sort(all(v), cmp);
    int ans = 0;
    pii pos = {0, 0};
    // for(auto [i, j]:v){
    //     cout<<i <<' '<<j<<'\n';
    // }
    while(1){
        auto it = lower_bound(all(v), pos);
        if(it == v.end())
            break;
        pos = {it->second, 0};
        ans++;
    }
    cout<<ans<<'\n';
}