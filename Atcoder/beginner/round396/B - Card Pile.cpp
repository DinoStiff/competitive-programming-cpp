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
    stack<int> s;
    int q;  
    cin >> q;

    for (int i = 0; i < 100; i++) {
        s.push(0);
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            s.push(x);
        } else if (op == 2) {
            cout << s.top() << '\n';
            s.pop();
        }
    }
}