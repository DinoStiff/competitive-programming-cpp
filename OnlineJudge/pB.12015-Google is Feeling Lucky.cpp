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
    int t, t2=0;
    cin>>t;
    while(t--){
        t2++;
        string s;
        int x, a=-1;
        vector<string> v[103];
        for(int i=0;i<10;i++){
            cin>>s>>x;
            v[x].push_back(s);
            a=max(a, x);
        }
        cout<<"Case #"<<t2<<":\n";
        for(auto i:v[a]){
            cout<<i<<'\n';
        }
    }
}