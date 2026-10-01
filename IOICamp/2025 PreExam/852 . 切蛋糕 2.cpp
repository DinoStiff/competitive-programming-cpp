#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e6+7;
int a[N], b[N], d[2][N], dp[2][N];

int main(){
    minji;
    int n, s1=0, s2=0, mx[2]={-20000, -20000}, l[2]={1, 1}, r[2]={1, 1};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s1+=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        d[0][i]=b[i]-a[i];
        d[1][i]=a[i]-b[i];
        s2+=b[i];
    }
    mx[0]=dp[0][0]=d[0][0];
    mx[1]=dp[1][0]=d[1][0];

    for(int k=0;k<2;k++){
        int el=1, er=1;
        for(int i=1;i<n;i++){
            if(d[k][i]>dp[k][i-1]+d[k][i]){
                dp[k][i]=d[k][i];
                el=i+1;
                er=i+1;
                if(dp[k][i]>mx[k]){
                    l[k]=el;
                    r[k]=er;
                    mx[k]=dp[k][i];
                }
            }
            else{
                dp[k][i]=dp[k][i-1]+d[k][i];
                er=i+1;
                if(dp[k][i]>mx[k]){
                    l[k]=el;
                    r[k]=er;
                    mx[k]=dp[k][i];
                }
            }
        }
    }
    mx[0]+=s1;
    mx[1]+=s2;
    int ans=max(s1, s2), al=-1, ar=-1;
    for(int i=0;i<2;i++){
        if(ans<mx[i]){
            al=l[i];
            ar=r[i];
            ans=mx[i];
        }
        //cout<<mx[i]<<'\n';
    }
    cout<<ans<<' '<<al<<' '<<ar<<'\n';

}