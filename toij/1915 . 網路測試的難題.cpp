#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;


int main(){
    minji;
    int t;
    cin >> t;
    while (t--){
        int n, m, ans=0;
        cin >> n >> m;
        int cnt[500005]={};
        vector <int> v[500005];
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            if (a < b) cnt[a]++;
            else cnt[b]++;
        }
        priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, cnt[i]);
            cnt[i] = v[i].size();
            pq.push({cnt[i], i});
        }
        cout << ans << " ";
        ans = 0;
        while (!pq.empty()){
            pair<int, int> tmp = pq.top();
            pq.pop();
            if (cnt[tmp.second] == -1) continue;
            ans = max(ans, tmp.first);
            cnt[tmp.second] = -1;
            for (auto i:v[tmp.second]){
                if (cnt[i] == -1) continue;
                cnt[i]--;
                pq.push({cnt[i], i});
            }
        }
        cout << ans << "\n";
    }
}