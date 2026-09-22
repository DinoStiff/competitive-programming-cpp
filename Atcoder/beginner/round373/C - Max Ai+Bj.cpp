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
    int n;
    cin >> n;
    ll a = -1e9;
    ll b = -1e9;
    ll x = 0;
    for(int i = 0;i < n;i++){
        cin >> x;
        a = max(a,x);
    }
    for(int i = 0;i < n;i++){
        cin >> x;
        b = max(b,x);
    }
    cout << a + b << endl;
}