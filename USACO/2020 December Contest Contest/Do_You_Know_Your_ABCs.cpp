#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int num[7], a, b, c;
	for (int i = 0; i < 7; i++) {
        cin >> num[i];
    }
	sort(num, num + 7);
	a = num[0];
    b = num[1];
	c = num[6] - a - b;
	cout << a << ' ' << b << ' ' << c << '\n';
}