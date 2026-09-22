#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    string s;
    cin>>s;
    char cur;
    int cnt = 0, tmp = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != cur) {
            cur = s[i];
            cnt = 0;
        }
        if (s[i] == cur) {
            cnt++;
        }
        tmp = max(tmp, cnt);
    }
    cout << tmp;
}