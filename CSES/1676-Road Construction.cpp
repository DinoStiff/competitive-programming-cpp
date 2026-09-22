#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

struct DSU {
	vector<int> e;
	void init(int n) { e = vector<int>(n, -1); }
	int get(int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
	bool sameSet(int x, int y) { return get(x) == get(y); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};

int main(){
    star;
    int n, m;
	cin >> n >> m;
	DSU dsu;
	dsu.init(n);
	int cc = n, large = 1;

	while (m--) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (dsu.unite(x, y)) {
			large = max(large, dsu.size(x));
			cc--;
		}
		cout << cc << ' ' << large << '\n';
	}
}