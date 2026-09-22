#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    string s, ans;
    cin>>s;
    int n = s.size(), tmp = 1;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            tmp=s[i]-'0';
            int j;
            for(j=i+1;j<n;j++){
                if(s[j]>='0'&&s[j]<='9'){
                    tmp*=10;
                    tmp+=s[j]-'0';
                }
                else{
                    break;
                }
            }
            i=j-1;
        }
        else{
            for(int j=0;j<tmp;j++){
                ans+=s[i];
            }
            tmp=1;
        }
    }
    cout<<ans<<'\n';
}