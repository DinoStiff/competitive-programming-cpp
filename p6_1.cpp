//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("avx2")

#include<bits/stdc++.h>
//#define int long long
//#define double long double
//const int INF = 4e18;
//using ll = long long;
//const int INF = 1e9;

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

#define tc template<class T>
tc using prq = priority_queue<T>;
tc using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define FOR(x,n) for (int x = 0; x < n; x++)
#define FOR1(x,n) for (int x = 1; x <= n; x++)

#define SZ(x) (int)(x.size())
#define pb push_back
#define mp make_pair
#define all(v) begin(v), end(v)

const int maxN = 2e5+5;
const int MOD = 998'244'353;

tc inline void chadd(T &a, T b) { a = (a+b) % MOD; }
tc inline void chmul(T &a, T b) { a = (a*b) % MOD; }
tc inline void chmin(T &a, T b) { a = min(a, b); }
tc inline void chmax(T &a, T b) { a = max(a, b); }

vector<pii> points;

void pre() {
    int d = 1;

    while ((int)points.size() < maxN) {
        for (int x = 1; x < d; x++) {
            int y = d - x;
            int g = __gcd(x, y);
            if (g == 1) {
                points.emplace_back(x, y);
            }
        }
        d++;
    }
}

void solve() {
    int n;
    cin >> n;
    auto [x, y] = points[n-1];
    cout << x << ' ' << y << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    pre();

    int t;
    cin >> t;
    while (t--) solve();
}
