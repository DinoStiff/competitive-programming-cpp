#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 20;

ll fact[N];

void init() {
    fact[0] = 1;
    for (int i=1; i<N; i++) {
        fact[i] = fact[i-1] * i;
    }
}

int main(){
    minji;
    ll t, n, x;
    cin >> t;
    init();
    string s;
    while (t--) {
        cin >> s >> n;
        string ans;
        sort(all(s));
        while (s.size() > 0) {
            int i;
            x = fact[s.size()-1];
            i = n / x;
            ans += s[i];
            s.erase(i, 1);
            n %= x;
        }
        cout << ans << '\n';
    }
}