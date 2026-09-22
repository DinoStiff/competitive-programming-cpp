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
    
    vector<ll> blk(n), wit(m);
    for (int i = 0; i < n; i++){
        cin >> blk[i];
    }
    for (int j = 0; j < m; j++){
        cin >> wit[j];
    }
    
    ll ans = 0;
    int tmp = 0;
    vector<ll> blk2;
    
    for (int i = 0; i < n; i++){
        if (blk[i] >= 0){
            ans += blk[i];
            tmp++;
        } else {
            blk2.push_back(blk[i]);
        }
    }
    sort(blk2.rbegin(), blk2.rend());
    
    vector<ll> wit2;
    for (int j = 0; j < m; j++){
        if (wit[j] > 0)
            wit2.push_back(wit[j]);
    }
    sort(wit2.rbegin(), wit2.rend());
    
    int tmp2 = 0;
    
    while (tmp2 < (int)wit2.size() && tmp > 0){
        ans += wit2[tmp2];
        tmp--;
        tmp2++;
    }
    
    int idx = 0;
    while (tmp2 < (int)wit2.size() && idx < (int)blk2.size()){
        ll cnt = wit2[tmp2] + blk2[idx];
        if (cnt > 0){
            ans += cnt;
            tmp2++;
            idx++;
        } else {
            break;
        }
    }
    
    cout << ans << "\n";
    return 0;
}