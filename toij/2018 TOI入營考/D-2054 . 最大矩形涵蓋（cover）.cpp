#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
//  y           x
map<int, vector<int>> m;

int main(){
    star;
    int n, l, w, ans = 0;
    cin>>n>>l>>w;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        m[b].push_back(a);
    }

    for(auto &i:m){
        sort(all(i.second));
    }
    for(auto i=m.begin();i!=m.end();i++){
        int y = (*i).first;
        for(int x:(*i).second){
            int sum=0;
            for(auto j=i;j!=m.end();j++){
                int ny = (*j).first;
                if(y+l<ny)
                    break;
                auto tmp = (*j).second;
                sum += upper_bound(all(tmp), x+w)-lower_bound(all(tmp), x);
                cout<<x<<' '<<y<<' '<<ny<<'\n';
            }
            ans = max(ans, sum);
        }
    }
    cout<<ans<<'\n';
    
}
