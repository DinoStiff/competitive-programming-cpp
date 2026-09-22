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
    int n, m;
    cin >> n >> m;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    vector<string> t(m);
    for (int i = 0; i < m; i++){
        cin >> t[i];
    }
    
    for (int i = 0; i <= n - m; i++){
        for (int j = 0; j <= n - m; j++){
            bool ok = true;
            for (int x = 0; x < m; x++){
                for (int y = 0; y < m; y++){
                    if (s[i+x][j+y] != t[x][y]){
                        ok = 0;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok){

                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
}