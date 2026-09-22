#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

bool cmp(pii a, pii b){
    return a.first>b.first;
}

int main(){
    minji;
    int n;
    cin>>n;
    vector<pii> v;
    int a, x;
    cin>>a;
    for(int i=1;i<n;i++){
        cin>>x;
        v.push_back({abs(x-a), i});
        a=x;
    }
    sort(all(v), cmp);
    for(int i=0;i<3;i++){
        cout<<v[i].first<<' '<<v[i].second<<' '<<v[i].second+1<<'\n';
    }
}