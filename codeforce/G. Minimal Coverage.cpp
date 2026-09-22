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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int f[3001], g[3001];
        memset(f, 1, sizeof f);
        f[0]=0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            memset(g, 1, sizeof g);
            for(int j=0;j<=2000;j++){
                g[max(0,j-x)] = min(g[max(0,j-x)], f[j]+x);
                g[j+x] = min(g[j+x], max(0, f[j]-x));
            }
            memcpy(f, g, sizeof f);
        }
        int ans=100001;
        for(int i=0;i<=2000;i++){
            ans=min(ans,i+f[i]);
        }
        
        cout << ans << endl;
    }
}
