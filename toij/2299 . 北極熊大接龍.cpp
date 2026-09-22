#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

vector<int> z_alg(string s){
    int n = s.size();
    vector<int> dp(n, 0);
    int l=0, r=1;
    for(int i=1;i<n;i++){
        int k = i;
        if(l<=i&&i<r){
            k = min(r, i+dp[i-l]);
        }
        while(s[k-i]==s[k]&&k<n){
            k++;
        }
        if(k>r){
            l=i;
            r = k;
        }
        dp[i] = k-i;
        //cout<<l<<' '<<r<<' '<<k<<'\n';
    }
    /* for(int i=0;i<n;i++){
        cout<<dp[i]<<' ';
    }
    cout<<'\n'; */
    return dp;
}

int solve(string s, int m){
    int n = s.size();
    vector<int> v = z_alg(s);
    int ans = -1;
    for(int i=m;i<n;i++){
        if(i+v[i]>=n)
            ans = max(ans, min(m-v[i], v[i]));
    }
    return ans;
}

int main(){
    nice;
    int n;
    string s, t;
    cin>>s>>n;
    while(n--){
        cin>>t;
        string str = t+s;
        cout<<solve(str, t.size())<<'\n';
    }
}