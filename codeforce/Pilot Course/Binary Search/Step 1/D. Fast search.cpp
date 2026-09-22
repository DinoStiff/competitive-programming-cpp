#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int k;
    cin >> k;

    int l, r;
    while (k--) {
        cin >> l >> r;
        auto a = lower_bound(v.begin(), v.end(), l);
        auto b = upper_bound(v.begin(), v.end(), r);

        cout << b - a <<' ';
    }
    cout << '\n';
}