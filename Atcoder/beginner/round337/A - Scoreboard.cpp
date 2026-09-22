#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 100+7;

int x, y, a, b;

int main(){
    star;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        x+=a;
        y+=b;
    }
    if(x>y){
        cout<<"Takahashi\n";
    }
    else if(x==y){
        cout<<"Draw\n";
    }
    else
        cout<<"Aoki\n";
}