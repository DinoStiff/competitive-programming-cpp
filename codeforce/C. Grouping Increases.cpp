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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(1, N), c(1, N);
        for (int i = 0; i < n; ++i) cin >> a[i];

        for (auto u : a) {
            if (b.back() > c.back())
                swap(b, c);
            int x = b.back();
            int y = c.back();
            if (x >= u)
                b.push_back(u);
            else if (u > y)
                b.push_back(u);
            else
                c.push_back(u);
        }
        int p1 = 0, p2 = 0;
        
        for (int i = 1; i < b.size()-1; ++i) {
            p1 += (b[i] < b[i + 1]);
        }
        
        for (int i = 1; i < c.size()-1; ++i) {
            p2 += (c[i] < c[i + 1]);
        }
        cout << p1 + p2 << '\n';
    }
}