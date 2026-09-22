#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int n, k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        if(*lower_bound(v.begin(), v.end(), a)==a)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}