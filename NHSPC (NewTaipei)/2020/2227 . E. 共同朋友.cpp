#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
bitset<2505> fd[2505];

int main(){
    star;
    int n, ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m, a;
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>a;
            fd[i][a]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((fd[i]&fd[j]).count()){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}