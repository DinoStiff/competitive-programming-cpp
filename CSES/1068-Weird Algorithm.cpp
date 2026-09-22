#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    ll n;
    cin>>n;
    while(n != 1){
        cout<<n<<" ";
        if(n % 2 == 1)n = 3 * n + 1;
        else n = n/2;
    }
    cout<<1<<"\n";
}