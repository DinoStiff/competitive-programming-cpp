#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    nice;
    int n, x;
	cin >> n >> x;
    vector<int> v(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		if (m.count(x - v[i])) {
			cout << i + 1 << " " << m[x - v[i]] << endl;
			return 0;
		}
		m[v[i]] = i + 1;
	}

	cout << "IMPOSSIBLE" << endl;

}