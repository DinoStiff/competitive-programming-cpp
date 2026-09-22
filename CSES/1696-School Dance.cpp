#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, m, k, a, b, match[505], used[505], ans;
vector <int> v[505];
  
bool dfs(int x, int tmp){
    for (int i:v[x]){
        if (!match[i]){
            match[i] = x;
            return 1;
        }
        else if (used[i]==tmp) continue;
        else{
            used[i] = tmp;
            if (dfs(match[i], tmp)){
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
  

int main(){
    nice;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        tmp++;
        if (dfs(i, tmp)) ans++;
    }
    cout << ans << "\n";
    for (int i = 1; i <= m; i++){
        if (match[i]){
            cout << match[i] << " " << i << "\n";
        }
    }
}