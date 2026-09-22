#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int n, m;
    cin>>n>>m;
    vector<int> v[n+1];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        while(x--){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    while(m--){
        int x;
        cin>>x;
        set<int> s;
        while(x--){
            int a;
            cin>>a;
            for(int i:v[a]){
                s.insert(i);
            }
        }
        cout<<s.size()<<'\n';
    }
}