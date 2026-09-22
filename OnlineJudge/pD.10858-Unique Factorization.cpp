#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

vector<vector<int>> ans;
vector<int> v;

void dfs(int x) {
    if (x == 1 && v.size() > 1) {
        ans.push_back(v);
        return;
    }
    int pre = v.empty() ? 2 : v.back();
    for (int y = pre; y <= x; y++) {
        if (x % y == 0) {
            v.push_back(y);
            dfs(x / y);
            v.pop_back();
        }
    }
}

int main(){
    minji;
    int n;
    while (cin >> n && n) {
        ans.clear();
        dfs(n);
        cout << ans.size() << '\n';
        for (auto i : ans)
            for (int j = 0; j < i.size(); j++)
                cout << i[j] << (j == i.size() - 1 ? '\n' : ' ');
    }
}