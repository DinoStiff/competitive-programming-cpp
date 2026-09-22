#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9;
const int N = 2e5+7;

map<int, int> cnt;

int main(){
    star;
    int n;
    string s;
    cin>>n;
    cin>>s;
    int len = 0, t=INF, sta = INF;
    bool ok=1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            len++;
        }
        else{\
            if(len){
                if(ok)
                    sta = len;
                else
                    t = min(t, len);
                cnt[len]++;
            }
            len=0;
            ok=0;
        }
    }
    t = (t+1)/2;
    if(len){
        t = min(t, len);
        cnt[len]++;
    }
    t = min(t, sta);
    
    //cout<<t<<endl;
    int ans = 0;
    for(auto i:cnt)
        ans += (i.first+2*t-2)/(2*t-1) * i.second;
    cout<<ans<<'\n';
}