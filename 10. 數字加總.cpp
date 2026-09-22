#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9;
const int N = 2e5+7;

int main(){
    minji;
    int n, ans = 0;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    while(v.size()>1){
        int a=INF, b;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]+v[i+1]<a){
                a=v[i]+v[i+1];
                b=i;
            }
        }
        v[b]=a;
        v.erase(v.begin()+b+1);
        ans+=a;
    }
    cout<<ans<<'\n';
}