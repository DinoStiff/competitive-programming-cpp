#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

vector<int> v(N);

int n;

bool check(){
    for (int i = 0; i <= n - 3; i++) {
        if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) {
            return 1;
        }
    }
    return 0;
}

int main(){
    minji;

    cin >> n;//輸入n


    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (check()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }int n;
}