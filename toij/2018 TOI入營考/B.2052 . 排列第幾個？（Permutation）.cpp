#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1030;
ll mod, c[N][N];
string s;
map<char, int> m;

//subtask 1, 3:40%
/*
int main(){
    star;
    cin>>mod>>s;
    t = s;
    sort(all(t));
    while(t!=s){
        next_permutation(all(t));
        ans++;
        ans%=mod;
    }
    cout<<ans<<'\n';
}*/

int main(){
    star;
    cin>>mod>>s;
    for (int i = 0; i <= 1024; i++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j++){
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    for(auto i:s){
        m[i]++;
    }
    ll ans = 0, idx=1;
    for(auto i:s){
        ll sum = 0;
        for(auto &j:m){
            if(j.first==i)
                break;
            ll tmp=1, l = s.size()-idx;
            j.second--;
            for(auto k:m){
                tmp*=c[l][k.second];
                tmp%=mod;
                l-=k.second;
            }
            sum+=tmp;
            sum%=mod;
            j.second++;
        }
        ans+=sum;
        ans%=mod;
        m[i]--;
        if(!m[i])
            m.erase(i);
        idx++;
    }
    cout<<ans<<'\n';
}