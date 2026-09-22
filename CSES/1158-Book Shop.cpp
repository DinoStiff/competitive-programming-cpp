#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e8+7;
const int N = 1e5+7;
int dp[N];
vector<int> pg, pr;

int main(){
    nice;
    int n, x, a;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        pr.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;
        pg.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=x;j>=pr[i];j--){
            dp[j]=max(dp[j], dp[j-pr[i]]+pg[i]);
        }
    }
    cout<<dp[x]<<'\n';
}
