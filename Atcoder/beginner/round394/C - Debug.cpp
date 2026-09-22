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
    string s;
    cin>>s;
    for(int i=s.size()-1;i>=1;i--){
        if(s[i]=='A'&&s[i-1]=='W'){
            s[i]='C';
            s[i-1]='A';
        }   
    }
    cout<<s<<'\n';
}