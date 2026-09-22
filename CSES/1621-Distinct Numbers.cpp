#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define milk ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    milk;
    int n, a;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a;
        s.insert(a);
    }
    cout<<s.size()<<'\n';
}