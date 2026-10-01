#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        char a;
        vector<int> v;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                cin>>a;
                if(a=='#')
                    cnt++;
            }
            if(cnt)
                v.push_back(cnt);
        }
        if(v.size()==1||v[0]==v[1])
            cout<<"ferb\n";
        else
            cout<<"phineas\n";
    }
}