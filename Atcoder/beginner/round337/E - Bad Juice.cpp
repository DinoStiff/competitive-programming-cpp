#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){

    int n;
    cin>>n;
    cout<<n-1<<endl;
    for(int i=1;i<n;i++){
        cout<<i<<' '<<i<<endl;
    }
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
}