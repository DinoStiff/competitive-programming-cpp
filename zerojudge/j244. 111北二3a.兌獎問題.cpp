#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

long long k, n, ans;
string t[3], s;

int main(){
    minji;
    cin >> k >> n;
    cin >> t[0] >> t[1] >> t[2];

    for(int i = 0; i < n; i++){
        cin >> s;
        int tmp = 0;
        for(int j = 0; j < 3; ++j)
        {
            if(s == t[j])                               tmp = max(tmp, 500000);
            else if(s.substr(2) == t[j].substr(2))      tmp = max(tmp, 10000);
            else if(s.substr(4) == t[j].substr(4))      tmp = max(tmp, 1000);
            else if(s.substr(k-3) == t[j].substr(k-3))  tmp = max(tmp, 300);
        }
        ans += tmp;
    }
    cout << ans << "\n";
}
