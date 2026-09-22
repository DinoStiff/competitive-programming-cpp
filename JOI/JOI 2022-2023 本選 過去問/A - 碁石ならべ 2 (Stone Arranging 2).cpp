#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
int a[N];
unordered_map<int, int> pos;
int main(){
    star;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    int tmp=-1;
    for(int i=1;i<=n;i++){
        if(tmp==-1&&i<pos[a[i]])
            tmp=a[i];
        else if(tmp>0){
            a[i]=tmp;
            if(i==pos[tmp])
                tmp=-1;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<'\n';
    }
}