#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define good_luck ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    good_luck;
    int a, c[9]={10000, 5000, 1000, 500, 100, 50, 10, 5, 1}, ans=0;
    cin >> a;
    for(int i=0;i<9;i++){
        ans+=a/c[i];
        a%=c[i];
    }
    cout<<ans<<'\n';
}