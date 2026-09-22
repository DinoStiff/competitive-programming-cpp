#include<bits/stdc++.h>
#define ll long long
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int N=2e5+5;

int n, a[N], b[N];
int main(){
    minji;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[n-i+1];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            bool ok=0;
            for(int j=1;j<=n;j++){
                if(b[j]!=a[i]&&b[i]!=a[j]){
                    swap(b[i],b[j]);
                    ok=1;
                    break;
                }
            }
            if(!ok){
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    cout<<'\n';
}
