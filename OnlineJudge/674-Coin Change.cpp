#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll ans[7490], coin[5]={1, 5, 10, 25, 50};

int main(){
    minji;
    ans[0]=1;
    for(int j=0;j<5;j++){
        for(int i=coin[j];i<7490;i++){
            ans[i]+=ans[i-coin[j]];
        }
    }
    int a;
    while(cin>>a){
        cout<<ans[a]<<'\n';
    }
}