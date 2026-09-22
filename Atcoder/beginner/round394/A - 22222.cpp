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
    int cnt = 0;
    cin>>s;
    for(auto i:s){
        if(i=='2'){
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++){
        cout<<"2";
    }
    cout<<'\n';
}