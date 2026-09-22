#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
 
const ll INF = 1e18, N = 2e3 + 7;
 
vector<int> v[N];
ll dis[N][N];
 
int main() {
    int n, q;
    cin >> n >> q;
    ll a, b, c;
    string s;
    cin>>s;
    for (int i = 1; i < n; i++) {
        if(s[i-1]=='0'&&s[i]=='0'){
            v[i].push_back(i+1);
            v[i+1].push_back(i);
        }
    }
    for (int i = 1; i <= n/2; i++) {
        if(s[i-1]=='0'&&s[n-i]=='0'){
            v[i].push_back(n-i+1);
            v[n-i+1].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=INF;
        }
    }
    while(q--){
        int s, t;
        cin>>s>>t;
        if(dis[s][t]!=INF){
            cout<<dis[s][t]<<'\n';
            continue;
        }
        queue<pii> pq;
        pq.push({0, s});
        while (pq.size()) {
            pii k = pq.front();
            if (dis[s][k.second] == INF) {
                dis[s][k.second] = dis[k.second][s] = -k.first;
                for (int i : v[k.second]) {
                    if (dis[s][i] == INF) {
                        pq.push({-(1 - k.first), i});
                    }
                }
            }
            pq.pop();
        }
        if(dis[s][t]==INF)
            cout<<-1<<endl;
        else
            cout << dis[s][t] << endl; 
    }
}
