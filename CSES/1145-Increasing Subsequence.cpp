#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define shadow ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    shadow;
    int n, a;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(v.empty()||v.back()<a){
            v.push_back(a);
        }
        *lower_bound(v.begin(), v.end(), a)=a;
    }
    cout<<v.size()<<'\n';
}