#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 200;

int amt[N];
vector<vector<int>> rec(N);

bool generate(int idx){
    if (amt[idx]>0){
        amt[idx]--;
        return 1;
    }
    
    if (rec[idx].size()==0)
        return 0;

    for (auto a : rec[idx]){
        if (!generate(a))
            return 0;
    }
    return 1;
}


int main(){
    star;

    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        amt[i] = a;
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        int l, m;
        cin >> l >> m;
        for (int j = 0; j < m; j++){
            int a;
            cin >> a;
            rec[l].push_back(a);
        }
    }

    int ans = amt[n];
    amt[n] = 0;

    while (generate(n)){
        ans++;
    }

    cout << ans << endl;
}