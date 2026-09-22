#include <bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int MAX = 2e5 + 9;

int n;

int b[MAX], sum;
int pos(int x) {
    return lower_bound(b + 1, b + 1 + sum, x) - b;
}

pll bit[MAX];
void update(int val, ll k) {
    for (int i=val; i <= sum; i += i&-i){
        bit[i].first += 1;
        bit[i].second += k;
    }
}
pll query(int val) {
    pll ans = {0, 0};
    for (int i=val; i>=1; i -= i&-i){
        ans.first += bit[i].first;
        ans.second += bit[i].second;
    }
    return ans;
}

struct Node {
    ll x, v;
    bool operator < (const Node &a) const {
        return x < a.x;
    }
} a[MAX];

int main() {
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i].x;
    for (int i = 1; i <= n; i++){
        cin>>a[i].v;
        b[++sum] = a[i].v;
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + sum);
    sum = unique(b + 1, b + 1 + sum) - (b + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        pll t = query(pos(a[i].v));
        ans += t.first * a[i].x - t.second;
        update(pos(a[i].v), a[i].x);
    }
    cout<<ans<<'\n';

    return 0;
}

	 	  									      	   	 					