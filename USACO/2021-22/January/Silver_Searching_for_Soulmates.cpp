#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

ll solve(ll a, ll b) {
	if (a == b) {
		return 0;
	} else if (a > b) {
		return 1 + a%2 + solve((a + a%2)/2, b);
	} else {
		return min(b - a, 1 + b%2 + solve(a, b/2));
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}