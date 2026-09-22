#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, q, f[200005][31], x, k;

int main(){
    nice;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> f[i][0];
    }
    for (int i = 1; i < 31; i++){
        for (int j = 1; j <= n; j++){
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
    while (q--){
        cin >> x >> k;
        for (int i = 0; i < 31; i++){
            if (k & (1<<i)){
                x = f[x][i];
            }
        }
        cout << x << "\n";
    }
}