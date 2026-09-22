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
    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int k1=0, k2=0;
    while(k1<n||k2<m){
        if(k1 == n){
            cout<<b[k2]<<' ';
            k2++;
        }
        else if(k2 == m){
            cout<<a[k1]<<' ';
            k1++;
        }
        else if(a[k1]<b[k2]){
            cout<<a[k1]<<' ';
            k1++;
        }
        else{
            cout<<b[k2]<<' ';
            k2++;
        }
    }
    cout<<'\n';
}