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
    while(getline(cin, s)){
        stringstream ss(s);
        int a, b, x=0;
        ss>>a;
        while(ss>>b){
            x=max(x, b);
        }
        if(x>=a)
            cout<<x<<"\n";
        else
            cout<<0<<"\n";
    }
}