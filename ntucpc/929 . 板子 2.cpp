#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18, mod = 998244353;
const int N = 2e5+7;

struct Vec{
	ll x, y;

    Vec(){
		x=0, y=0;
	}
	Vec(ll a, ll b){
		x=a, y=b;
	}
	Vec operator + (Vec b){
		return {x+b.x, y+b.y};
	}
	Vec operator - (Vec b){
		return {x-b.x, y-b.y};
	}
	ll operator ^ (Vec b){
		return x*b.y-y*b.x;
	}
};

istream& operator >> (istream& is, Vec &a){
    is>>a.x>>a.y;
    return is;
}

int main(){
    minji;
    int n;
    cin>>n;
    Vec v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans = 0, dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dp[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                ll a = abs((v[k]-v[i])^(v[j]-v[i])); //abs((v[k]-v[i])^(v[j]-v[i]))--> area
                if(a){
                    dp[i][j] = min(dp[i][j], a);
                    dp[i][k] = min(dp[i][k], a);
                    dp[j][k] = min(dp[j][k], a);
                }
            }
            ans = (ans+dp[i][j])%mod;
        }
    }
    cout<<ans<<'\n';
}