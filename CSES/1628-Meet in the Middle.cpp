#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end() 
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 47;

ll n, k;
vector<ll> x(N), a, b;

void findall(int l, int r, ll sum){
    if(l>r){
        if(r==n/2-1)
            a.push_back(sum);
        else
            b.push_back(k-sum);
        return;
    }
    findall(l+1, r, sum);
    findall(l+1, r, sum+x[l]);
}

int main(){
    star;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    findall(0, n/2-1, 0);
    findall(n/2, n-1, 0);
    sort(all(b));
    ll ans=0;
    for(auto i:a){
        ans+=upper_bound(all(b), i)-lower_bound(all(b), i);
    }
    cout<<ans<<'\n';
}