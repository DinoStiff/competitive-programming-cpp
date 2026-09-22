#include <bits/stdc++.h>
#define ll long long
#define pic pair<ll, char>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int n;
    cin>>n;
 
    vector<pic> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i].second>>v[i].first;
    }
 
    int ans = N;
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < i; j++){
            if (v[j].second == 'L')
                cnt++;
        }
        for (int j = i+1; j < n; j++){
            if (v[j].second == 'G')
                cnt++;
        }
        ans = min(cnt, ans);
    }
 
    cout<<ans<<'\n';
}