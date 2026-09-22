#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define matrix vector<vector<ll>>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
const ll mod = 1e9+7;

matrix in;

matrix operator * (matrix a, matrix b){
    ll l=b.size(), n = a.size(), m = b[0].size();
    matrix tmp(n, vector<ll>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                //cout<<i<<' '<<j<<' '<<k<<endl;
                tmp[i][j] = (tmp[i][j]+a[i][k]*b[k][j] %mod)%mod;
            }
        }
    }
    return tmp;
}

matrix Pow(ll k, matrix v){
    matrix tmp = in;
    while(k){
        if(k&1){
            tmp = tmp*v;
        }
        v = v*v;
        k>>=1;
    }
    return tmp;
}

int main(){
    star;
    ll n, k;
    cin>>n>>k;
    in.resize(n, vector<ll>(n, 0));
    matrix mx(n, vector<ll>(n)), ans(n, vector<ll>(1, 1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mx[j][i];
            if(i==j)
                in[i][j]=1;
        }
    }
    ans = Pow(k,mx)*ans;
    ll sum=0;
    for(int i=0;i<n;i++){
        sum = (sum+ans[i][0])%mod;
    }
    cout<<sum<<'\n';
}