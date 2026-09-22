#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
using namespace std;

const ll inf = 1e16;
const ll N = 5e5 + 10;
const ll mod = 1e9 + 7;
ll n, m, k;

int bit[N];
int lowbit(int i) {
    return i & -i;
}
void add(int i, int c) {
    for (;i <= n * 3;i += i&-i) {
        bit[i] += c;
    }
}
int sum(int i) {
    int sum = 0;
    for (;i;i -= i&-i)sum += bit[i];
    return sum;
}


void solve() {
    cin >> n;
    vector<int>a(3*n + 1);
    int mx = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
        a[i+n] = a[i];
        a[i+n*2] = a[i];
    }
    int tmp = 1;
    for (int i = 1;i <= n;i++) {
        if (a[i] < (mx+1) / 2) {
            tmp = 0;
            break;
        }
    }
    if (tmp) {
        for (int i = 1;i <= n;i++) {
            cout << -1 << " ";
        }
        cout << "\n";
        return;
    }
    priority_queue<pii>pq;
    int pre = 0;
    for (int i = 1;i <= 3 * n;i++) {
        if (!pq.empty() && (pq.top().first + 1) / 2 > a[i]) {
            
            while (!pq.empty() && (pq.top().first + 1) / 2 > a[i]) {
                while (!pq.empty()&&pq.top().second <= pre) {
                    pq.pop();
                }
                if (pq.empty())
                    break;
                if (!pq.empty() && (pq.top().first + 1) / 2 <= a[i])
                    break;
                auto [x, pos] = pq.top();
                add(pre + 1, i-1);
                add(pos + 1, -(i-1));
                pre = pos;
            }
        }
        pq.push({ a[i],i });
    }
    for (int i = 1;i <= n;i++) {
        int res = sum(i);
        cout << res - i + 1 << " ";
    }

}
signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
