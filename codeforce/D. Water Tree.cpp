#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
using namespace std;
const int oo = 1e9 + 9;
const int MAX = 5e5 + 4, B = 400;
int n, q;

vector<int> vec[MAX];
int in[MAX], out[MAX], pr[MAX];
int t = 0;
void dfs(int x, int p){
    pr[x] = p;
    in[x] = ++t;
    for(int i : vec[x]){
        if(i == p) continue;
        dfs(i, x);
    }
    out[x] = t;
}  

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set<int> s;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++){
        s.insert(in[i]);
    }
    cin >> q;
    while(q--){
        int c, v;
        cin >> c >> v;
        if(c == 1){
            auto it = s.lower_bound(in[v]);
            bool ok = 0;
            while(it != s.end() && *it <= out[v]){
                s.erase(it);
                ok = 1;
                it = s.lower_bound(in[v]);
            }
            if(ok && v != 1) s.insert(in[pr[v]]);
        }
        if(c == 2){
            s.insert(in[v]);
        }
        if(c == 3){
            auto a = s.lower_bound(in[v]);
            auto b = s.upper_bound(out[v]);
            if(a != s.end() && b != s.begin() && *a <= *prev(b)) cout << "0\n";
            else cout << "1\n";
        }
    }
}