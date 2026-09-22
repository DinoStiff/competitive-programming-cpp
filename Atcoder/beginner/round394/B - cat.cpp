#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

bool cmp(string a, string b){
    if(a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}

int main(){
    minji;
    int n;
    cin>>n;
    vector<string> v(n);
    for(auto &i:v){
        cin>>i;
    }
    sort(all(v), cmp);
    for(auto i:v){
        cout<<i;
    }
    cout<<'\n';
}