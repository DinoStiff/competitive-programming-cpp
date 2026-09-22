#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin>> a[i];
        }
        int x, y, z;
        if(n==2){
            if(a[0]==a[1]){
                cout<<a[0]<<'\n';
            }
            else{
                cout<<-1<<'\n';
            }
        }
        else{
            x=a[0];
            y=a[1];
            z=a[2];
            set<int> ans;
            for(int i = 3; i < n; i++){
                if(x==y||x==z||y==z){
                    if(x==y||x==z)
                        ans.insert(x);
                    else
                        ans.insert(y);
                }
                x=y;
                y=z;
                z=a[i];
            }
            if(x==y||x==z||y==z){
                if(x==y||x==z)
                    ans.insert(x);
                else
                    ans.insert(y);
            }
            if(ans.empty())
                cout<<-1;
            for(auto i=ans.begin();i!=ans.end();i++){
                cout<<*i;
                if(i!=prev(ans.end()))
                    cout<<' ';
            }
            cout<<'\n';
        }
    
    }

}