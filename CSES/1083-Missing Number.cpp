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
    int n;
    cin>>n;
    vector<int> v(n-1);
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    sort(all(v));
    for(int i=0;i<n-1;i++){
        if(i+1!=v[i]){
            cout<<i+1<<'\n';
            return 0;
        }
    }
    cout<<n<<'\n';
}