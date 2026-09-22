#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define vi vector<ll>
#define vii vector<vi>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17, mod = 1e9+7;
const int N = 2e5+7;

ll n;
vii in(2, vi(2, 0)), fac(2, vi(2)), ans(2, vi(1));

vii operator * (vii a, vii b){
    ll l = b.size(), n = a.size(), m = b[0].size();
    vii res(n, vi(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%mod)%mod;
            }
        }
    }
    return res;
}

vii Pow(ll k, vii d){
    vii res = in;
    while(k){
        if(k&1){
            res = res*d;
        }
        d = d*d;
        k>>=1;
    }
    return res;
}

int main(){
    star;
    in[0][0]=1;
    in[1][1]=1;
    fac[0][0]=0;
    fac[0][1]=1;
    cin>>ans[0][0]>>ans[1][0]>>fac[1][0]>>fac[1][1]>>n;
    cout << (Pow(n-2, fac) * ans)[1][0] << '\n';

}