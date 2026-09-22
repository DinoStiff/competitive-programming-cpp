#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, e;
    cin >> n >> k >> e;
    vector<int> h(e + 1, 0), st(k), v(e + 1, -1);
    while (n--)
    {
        int x;
        cin >> x;
        h[x] = 1;
    }
    for (int &i : st)
        cin >> i;
    vector<vector<pair<int, int>>> dp(e + 1);
    for (int i = 1; i <= e; i++)
    {
        if (h[i]) continue;
        for (int j : st)
        {
            if (i < j || (i > j && dp[i - j].empty())) continue;
            auto tmp = dp[i - j];
            auto it = lower_bound(tmp.begin(), tmp.end(), make_pair(j, e + 1), greater<>());
            if (it == tmp.end() || it->first != j)
                tmp.insert(it, make_pair(j, 1));
            else
                it->second += 1;
            if (tmp > dp[i])
            {
                dp[i] = tmp;
                v[i] = i - j;
            }
        }
    }
    if (dp[e].empty())
        cout << "-1\n";
    else
    {
        vector<int> ans;
        for (; e; e = v[e])
            ans.push_back(e);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int i = 0; i < int(ans.size()); i++)
            cout << ans[i] << " \n"[i + 1 == int(ans.size())];
    }
}