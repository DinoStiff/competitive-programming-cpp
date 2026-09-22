#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e9;
const int N = 2e5+7;

int main(){
    minji;
    int n;
    cin>>n;
    int rank[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            rank[i][x]=j;
        }
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
        }
    }
    string s="";
    for(int i=1;i<=n;i++){
        s+=('0'+i);
    }
    int ans = INF;
    string ord;
    while(next_permutation(all(s))){
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt+=rank[i+1][s[i]-'0'];
        }
        if(s=="3124")
            cout<<cnt<<'\n';
        if(cnt<ans){
            ord = s;
            ans = cnt;
        }
    }
    for(auto i:ord){
        cout<<i<<' ';
    }
    cout<<'\n';
    cout<<ans;
}