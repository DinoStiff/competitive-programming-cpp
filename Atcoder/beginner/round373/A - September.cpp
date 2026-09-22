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
    int ans = 0;
    for(int i = 1; i <= 12; i++) {
        string s;
        cin>>s;
        if(s.size() == i) ans++;
    }
    cout << ans << endl;

}