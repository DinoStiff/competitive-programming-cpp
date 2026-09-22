#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define good_luck ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

map<int, int> mp;

void update(int x) {
    if (!mp[x]){
        mp[x]++;
        return;
    }
    mp.erase(x);
}

int main() {
    good_luck;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        b++;
        update(a);
        update(b);
    }
    vector<pii> ans;
    copy(all(mp), back_inserter(ans));
    int sum = 0;
    for (int i = 0;i < ans.size();i++){
        sum += ans[i+1].first - ans[i].first;
        i++;
    }
    cout << n-sum << "\n";
}