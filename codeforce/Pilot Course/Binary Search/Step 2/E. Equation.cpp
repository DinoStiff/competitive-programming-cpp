#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e6;
const int N = 2e5+7;

int main(){
    star;
    double c;
    cin >> c;

    double l = 0;
    double r = INF;
    for (int i = 0; i < 50; i++) {
        double k = (r + l) / 2;
        double tmp = k * k + sqrt(k);
        if (tmp > c) {
            r = k;
        } else {
            l = k;
        }
    }

    cout << setprecision(10) << r << endl;
}