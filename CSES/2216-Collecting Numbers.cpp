#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define shadow ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    shadow;
    int n;
    cin>>n;
    int a[n+2], x, ans=1;
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]=i;
    }
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1])
            ans++;
    }
    cout<<ans<<'\n';
}