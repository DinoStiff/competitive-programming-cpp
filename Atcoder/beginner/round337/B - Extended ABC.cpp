#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;


int main(){
    star;
    string s;
    cin>>s;
    int i=0;
    while(i<s.size()&&s[i]=='A')
        i++;
    while(i<s.size()&&s[i]=='B')
        i++;
    while(i<s.size()&&s[i]=='C')
        i++;
    if(i==s.size())
        cout<<"Yes\n";
    else
        cout<<"No\n";
}