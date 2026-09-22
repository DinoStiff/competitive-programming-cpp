#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define m first
#define k second
#define pii pair<ll, ll>
#define strawberry ios::sync_with_stdio(false), cin.tie(0)
const ll N = 200005, INF = LLONG_MAX;
ll n, c;

deque<pii> line;
ll h[N], dp[N];

ll cal(ll x, pii var) {/*cout<<var.m<<' '<<var.k<<' '<<var.m * h[x] + var.k<<endl;*/ return var.m * h[x] + var.k; }

pii key(ll x) { return {-2 * h[x], dp[x] + h[x] * h[x]}; }

void search(ll x) {
    //cout<<x<<':'<<endl;
    dp[x] = cal(x, line[0]);
    while (line.size() >= 2 && dp[x] > cal(x, line[1])) {
        line.pop_front();
        dp[x] = cal(x, line[0]);
        //cout<<dp[x]<<' ';
    }
    //cout<<endl;
    dp[x]+=c+h[x]*h[x];
}

void add(pii var) {
    double x1, x2;
    while (line.size()>=2) {
        int l=line.size();
        x1 = 1.0*(line[l-2].k - line[l-1].k) / (line[l-1].m - line[l-2].m);
        //cout<<line[l-1].m<<endl;
        x2 = 1.0*(line[l-2].k - var.k) / (var.m - line[l-2].m);
        //cout<<x1<<' '<<x2<<endl;
        if (x2 < x1)
            line.pop_back();
        else
            break;
    }
    line.push_back(var);
}

int main() {
    strawberry;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    line.push_front(key(1));
    for (int i = 2; i <= n; i++) {
        search(i);
        add(key(i));
    }
    /*
    for(int i=1;i<=n;i++){
    cout<<dp[i]<<' ';
    }
    */
    cout << dp[n] << endl;
}