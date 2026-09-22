#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

ll dp[N], amt[N], bmt[N], ans;

int main(){
    star;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        amt[a]++;
        bmt[b]++;
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            dp[i+j]+=amt[i]*amt[j];
            dp[i+j+1]-=bmt[i]*bmt[j];
        }
    }
    for(int i=0;i<=2*m;i++){
        ans+=dp[i];
        cout<<ans<<'\n';
    }
}