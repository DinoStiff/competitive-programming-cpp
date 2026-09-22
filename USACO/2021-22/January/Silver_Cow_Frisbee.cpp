#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int n;
    cin >> n;
    ll ans = 0;
    deque<pii> dq;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        while(dq.size()&&dq.back().first<a){
            ans+=(i-dq.back().second)+1;
            dq.pop_back();
        }
        if(dq.size())
            ans+=(i-dq.back().second)+1;
        dq.push_back({a, i});
    }
	cout << ans << '\n';
}