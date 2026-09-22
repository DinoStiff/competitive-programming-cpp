#include <bits/stdc++.h>
#define int long long
#define MAXN 500005
#define MAXM 1000005 
int n, k;
int x[MAXN], pre[MAXN], dp[MAXN];
using namespace std;


struct ln {
    int a, b;
    int operator ()(int _x) {
        return a * _x + b;
    }
};

bool check(ln l1, ln l2, ln l3, int _x) {
    return ((l1.b - l2.b) * (l3.a - l2.a) > (l2.a - l1.a) * (l2.b - l3.b) && (_x + k) * (l3.a - l2.a) > (l2.b - l3.b));
}

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    reverse(x + 1, x + n + 1);
    for (int i = 1; i <= n; i++)   
        pre[i] = pre[i - 1] + x[i];

    deque<pair<ln, int>> dq;
    dq.push_back({{0, 0}, 0});

    for (int i = 1; i <= n; i++) {
        while (dq.size() && dq.front().second < i - k)
            dq.pop_front();
        while (dq.size() >= 2 && dq[0].first(i) < dq[1].first(i))
            dq.pop_front();

        dp[i] = -i * i + dq.front().first(i);

        ln now = {2 * i, dp[i] - i * i + pre[i]};
        while (dq.size() >= 2 && check(dq[dq.size() - 2].first, dq[dq.size() - 1].first, now, dq[dq.size() - 2].second))
            dq.pop_back();
        dq.push_back({now, i});
    }
    cout << dp[n] << endl;
    return 0;
}