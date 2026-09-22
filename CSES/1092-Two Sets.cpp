#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    nice;
    int n;
    cin>>n;
    if(n%4==1||n%4==2){
        cout<<"NO\n";
    }
    else{
        if(n%4==3){
            cout<<"YES\n";
            cout<<n/2+1<<'\n';
            for(int i=1;i<=n/2;i+=2){
                cout<<i<<' '<<n-i<<' ';
            }
            cout<<'\n'<<n/2<<'\n';
            for(int i=2;i<=n/2;i+=2){
                cout<<i<<' '<<n-i<<' ';
            }
            cout<<n<<'\n';
        }
        else{
            cout<<"YES\n";
            cout<<n/2<<'\n';
            for(int i=1;i<=n/2;i+=2){
                cout<<i<<' '<<n-i+1<<' ';
            }
            cout<<'\n'<<n/2<<'\n';
            for(int i=2;i<=n/2;i+=2){
                cout<<i<<' '<<n-i+1<<' ';
            }
            cout<<'\n';
        }
    }
}