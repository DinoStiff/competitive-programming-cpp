#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

struct Cow {
	int x, y;
	int idx;
};

int main() {
    star;
	int n;
	cin >> n;
	vector<Cow> north;
	vector<Cow> east;

	for (int i = 0; i < n; i++) {
		char dir;
		int x, y;
		cin >> dir >> x >> y;
		if (dir == 'N') {
			north.push_back({x, y, i});
		} else if (dir == 'E') {
			east.push_back({x, y, i});
		}
	}

	sort(north.begin(), north.end(), [&](const Cow &c1, const Cow &c2) { return c1.x < c2.x; });
	sort(east.begin(), east.end(), [&](const Cow &c1, const Cow &c2) { return c1.y < c2.y; });

	vector<int> stop(n, -1);
	for (auto nc : north) {
		for (auto ec : east) {
			if (nc.x > ec.x && nc.y < ec.y) {
				int nt = ec.y - nc.y;
				int et = nc.x - ec.x;
				if (nt < et && stop[ec.idx] == -1)  stop[ec.idx] = nc.x;
				if (nt > et && stop[ec.idx] == -1) {
					stop[nc.idx] = ec.y;
					break;
				}
			}
		}
	}

	vector<int> dis(n, -1);
	for (auto nc : north) {
		if (stop[nc.idx] != -1) dis[nc.idx] = stop[nc.idx] - nc.y;
	}

	for (auto ec : east) {
		if (stop[ec.idx] != -1) dis[ec.idx] = stop[ec.idx] - ec.x;
	}

	for (int i : dis) {
		cout << (i == -1 ? "Infinity" : to_string(i)) << '\n';
	}
}