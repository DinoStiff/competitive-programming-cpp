#include <bits/stdc++.h>
#include <bits/extc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m, t, k ,r;
    cin>>n>>m>>t>>k>>r;
    vector<int> v;
    int pre[n+7];
    ll ans=0;
    pre[0]=0;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int l = max(1, r-k+1)+min(n, r+k-1)-k;
    //cout<<l<<'\n';
    for(int i=k;i<=m;i++){
        int cnt = upper_bound(v.begin(), v.end(), i) - upper_bound(v.begin(), v.end(), i-k);
        //cout<<i<<' '<<cnt<<'\n';
        if(cnt%2==0&&k%2==1){
            ans+=l;
        }
        else if(cnt%2==1&&k%2==0){
            ans+=l;
        }
    }
    cout<<ans<<'\n';
}

