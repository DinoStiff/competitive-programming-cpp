#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int solve(string s, int x){
    int ans=0;
    int n = s.size();
    //cout<<s<<":\n";
    for(int i=0;i<n;i++){
        int tmp = s[i]-'0', cnt = 1;
        if(i){
            cnt = stoi(s.substr(0, i));
        }
        //cout<<tmp<<": ";
        if(!x&&!i){
            continue;
        }
        if(x<tmp){
            if(!x||!i){
                cnt--;
            }
            ans+=(cnt+1)*pow(10, n-i-1);
        }
        else if(x==tmp){
            if(i+1<n)
                ans+=stoi(s.substr(i+1));
            ans++;
            //cout<<"="<<s.substr(i+1)<<' '<<ans<<' ';
            if(!x|!i){
                cnt--;
            }
            if(i){
                ans+=cnt*pow(10, n-i-1);
            }
        }
        else{
            if(!x|!i){
                cnt--;
            }
            if(i){
                ans+=cnt*pow(10, n-i-1);
            }
        }
        //cout<<ans<<'\n';
    }
    //cout<<'\n';
    return ans;
}

int main(){
    minji;
    string a, b;
    while(cin>>a>>b&&a!="0"&&b!="0"){
        if(a>b)
            swap(a, b);
        a[a.size()-1]--;
        for(int i=0;i<10;i++){
            cout<<solve(b, i) - solve(a, i)<<" ";
        }
        cout<<'\n';
    }
}