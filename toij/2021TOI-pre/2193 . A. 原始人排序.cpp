#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

bool cmp(int x, int y){
    return __builtin_popcount(x) < __builtin_popcount(y);
}

int main(){
    star;
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    stable_sort(all(v), cmp);
    for(int i:v){
        cout<<i<<' ';
    }
    cout<<'\n';
}