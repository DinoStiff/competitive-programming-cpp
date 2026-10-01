#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    ll n, ans=0;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        ll a=arr[i], b=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<a){
                a=arr[j];
                b=j;
            }
        }
        ans+=(arr[i]+arr[b])*(b-i);
        swap(arr[i], arr[b]);
    }
    cout<<ans<<'\n';
}