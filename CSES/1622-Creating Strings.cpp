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
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    vector<string> v;
    v.push_back(s);
    while(next_permutation(s.begin(), s.end())){
        v.push_back(s);
    }
    cout<<v.size()<<'\n';
    for(auto i:v){
        cout<<i<<'\n';
    }
}