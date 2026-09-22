#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

ll n, k, id[N], a[N*2];

int main(){
    minji;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }

    ll r=0, sum=0;

    for(int l=0;l<n;l++){
        while(r<l+n && sum+a[r] <= k){
            sum += a[r];
            r++;
        }
        sum -= a[l];
        id[l] = r%n;
    }

    int tmp = 0;
    for(int i=0;i<n;i++){
        tmp = id[tmp];
    }
    ll ans = 1, cnt = a[tmp];
    for(int i=tmp+1;i<n+tmp;i++){
        if(cnt+a[i] > k){
            cnt = a[i];
            ans++;
        }
        else
            cnt += a[i];
    }
    cout<<ans<<'\n';
}