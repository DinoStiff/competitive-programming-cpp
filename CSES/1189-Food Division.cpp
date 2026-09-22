#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;
int n, arr[N];

int main(){
    minji;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    for(int i = 1; i <= n; i++){
        int a;
        cin>>a;
        arr[i] += (arr[i-1] - a);
    }
    sort(arr+1, arr+n+1);

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += abs(arr[i] - arr[(n+1)/2]);
    }
    cout<<ans<<'\n';
}