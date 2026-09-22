#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

string s;

int main(){
    minji;
    while(getline(cin, s)){
        int cnt[130]={};
        string ans[1001];
        for(auto i:s){
            cnt[i]++;
        }
        for(int i=128;i>=0;i--){
            ans[cnt[i]]+=i;
        }
        for(int i=1;i<=1000;i++){
            for(auto j:ans[i]){
                cout<<(int)j<<' '<<i<<'\n';
            }
            cout<<'\n';
        }
    }
}