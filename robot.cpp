#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

P operator+(pii a, pii b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }

vector<pair<P, int>> all_subsets(const vector<P> &dirs) {
	vector<pair<P, int>> v{{}};
	for (const P &d : dirs) {
		v.resize(2 * v.size());
		for (int i = 0; i < v.size() / 2; i++) {
			v[i + v.size() / 2] = {v[i].first + d, v[i].second + 1};
		}
	}
	return v;
}

struct hsh {
	size_t operator()(const P &p) const {
		return p.first * 239 + p.second;
	}
};

int main(){
    star;
    int N;
	cin >> N;
	pii goal;
	cin >> goal.first >> goal.second;
	vector<pii> dirs(N);
	for (auto &d : dirs) {
		cin >> d.first >> d.second;
	}
	vector<pair<pii, int>> a =
		all_subsets(vector<P>(begin(dirs), begin(dirs) + N / 2));
	vector<pair<P, int>> b =
		all_subsets(vector<P>(begin(dirs) + N / 2, end(dirs)));
	unordered_map<P, map<int, int>, hsh> first_half;
	for (const auto &[offset, num] : a) {
		++first_half[offset][num];
	}
	vector<long long> ans(N + 1);
	for (const auto &[offset, num] : b) {
		auto it = first_half.find(goal - offset);
		if (it != end(first_half)) {
			for (const auto &[num2, ways] : it->second) {
				ans[num + num2] += ways;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
}