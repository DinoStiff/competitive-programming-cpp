#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9+7;
const int N = 5007;

int n, pos[N], dp[N];

struct BIT{
    int bit[N];
    void clear(){
        memset(bit, 0, sizeof bit);
    }

    void add(int k, int v){
        for(int i=k; i<=n; i += (i&-i)){
            bit[i]+=v;
        }
    }

    int query(int k){
        int ans = 0;
        for(int i=k; i>0; i -= (i&-i)){
            ans+=bit[i];
        }
        return ans;
    }

}a, b;

int main(){
    star;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pos[x]=i;
    }
    for(int i=1;i<=n;i++){
        int move = 0;
        dp[i] = INF;
        a.add(pos[i], 1);
        b.clear();
        for(int j=i;j>=1;j--){
            move -= b.query(pos[j]);
            //cout<<j<<' '<<pos[j]<<' '<<b.query(pos[j])<<' ';
            move += i - a.query(pos[j]);
            dp[i] = min(dp[i], dp[j - 1] + move);
            b.add(pos[j], 1);
            //cout<<i - a.query(pos[j])<<' '<<move<<'\n';
        }
        //cout<<dp[i]<<"\n\n";
    }
    cout<<dp[n]<<'\n';
}