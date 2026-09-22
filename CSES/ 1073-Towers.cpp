#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n;
vector<int> v;

int main() {
    minji;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		int l = 0, r = v.size();
		while (l < r) {
			int mid = (l + r) / 2;
			if (v[mid] > x) r = mid;
			else l = mid + 1;
		}
		if (l == v.size()) v.push_back(x);
		else v[l] = x;
	}
	cout << v.size();
}