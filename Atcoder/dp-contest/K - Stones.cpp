#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;


int a[105];
int dp[N];

int n,k;

bool rec(int amt){
    if (dp[amt] != -1)
        return dp[amt];
    
    for(int j=0; j<n; j++){
        if (amt >= a[j] && !rec(amt-a[j])){
            return dp[amt] = 1;
        }
    }
    
    return dp[amt] = 0;
}


int main(){
    star;

    memset(dp , -1 , sizeof dp);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<(rec(k) ? "First" : "Second");
}