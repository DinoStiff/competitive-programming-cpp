#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 45;


int c, t, tn;
int p[N], s[N], n[N], r[N][N];
vector<int> dp[N];
struct Psum {
    vector<int> x;
    Psum() {}
    Psum(int _n, int _x[]) {
        x.clear();
        x.push_back(0);
        REP(i,1,_n) {
            x.push_back(x.back() + _x[i]);
        }
    }
    int sum(int l,int r) {
        if (l > r) return 0;
        return x[r] - x[l-1];
    }
}ps, ns, rs[N];
void init() {
    REP(i,1,c) cin>>p[i];
    REP(i,1,c) cin>>s[i];
    REP(i,1,c) cin>>n[i];
    REP(i,1,c) REP(j,1,i) cin>>r[i][j];

    ps = Psum(c, p);
    ns = Psum(c, n);
    REP(i,1,c) rs[i] = Psum(c, r[i]);
    tn = accumulate(n+1, n+1+c, 0);
}
void work() {
    REP(i,0,c) dp[i] = vector<int> (tn+1, INF);
    dp[0][0] = 0;

    REP(i,1,c) REP(j,0,tn) REP(k,0,i-1) {
        int dt  = ps.sum(1, i) * ns.sum(k+1, i);
            dt += s[i] * ns.sum(k+1, i);
        int dr = rs[i].sum(k+1, i);

        if (j>=dr && dp[k][j-dr] != INF) {
            dp[i][j] = min(dp[i][j], dp[k][j-dr] + dt);
        }
    }

    int ans = -1;
    REP(i,0,c) REP(j,0,tn) if (dp[i][j] != INF) {
        int dt = ps.sum(1, c) * ns.sum(i+1, c);
        if (dp[i][j]+dt <= t) {
            ans = max(ans, j);
        }
    }
    cout<<ans<<'\n';
}

int main(){
    minji;
    cin>>c>>t;
    init();
    work();
}