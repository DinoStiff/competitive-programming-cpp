#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

void solve(){
    int n, k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
    }
    vector<vector<int>> tasks(k);
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            int x;
            cin>>x;
            tasks[i].push_back(x);
        }
    }
    // for(int i=0;i<k;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<tasks[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
                return a[1] < b[1];
        });
    vector<tuple<int, int, int>> st{{-1e9+7, -1e9+7, 0}};
    for (auto &t : tasks) {
        int start = t[0], end = t[1], d = t[2];
        auto[_, r, s] = *--lower_bound(st.begin(), st.end(), start, [](const auto &a, int b) {
            return get<0>(a) < b;
        });
        d -= get<2>(st.back()) - s;
        if (start <= r)
            d -= r - start + 1;
        if (d <= 0) continue;
        while (end - get<1>(st.back()) <= d) {
            auto[l, r, _] = st.back();
            d += r - l + 1;
            st.pop_back();
        }
        st.emplace_back(end - d + 1, end, get<2>(st.back()) + d);
    }
    cout<<n-get<2>(st.back())<<'\n';
}

int main(){
    minji;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
   
}