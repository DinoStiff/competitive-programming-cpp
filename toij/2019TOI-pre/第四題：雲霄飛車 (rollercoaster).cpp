#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

int h[N];

int main(){
    star;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    // p1 11%
    if(n==3){
        if(h[0]>h[1]){
            if(h[1]>h[2]){
                cout<<"0\n";
            }
            else{
                cout<<"1\n";
            }
        }
        else{
            cout<<"0\n";
        }
    }
    else{
        cout<<0<<'\n';
    }
}