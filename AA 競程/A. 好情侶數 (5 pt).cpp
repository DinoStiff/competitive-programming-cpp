#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

bool solve(ll n) {
   for(ll  a = 1; a * a <= n; a++) {
       if(n % a == 0) {
            ll b = n / a;
            if(a * 2 >= b) return 1;
       }
   }
   return 0;
}

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}

