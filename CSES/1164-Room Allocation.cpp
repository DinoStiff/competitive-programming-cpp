#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int n;
int ans[N];
vector<pair<pii, int>> v(N);

int main(){
    minji;
    cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
	}
	sort(all(v));

	int cur = 0, lt = 0;
	priority_queue<pii> pq;
	for (int i = 0; i < n; i++) {
		if (pq.empty()) {
			lt++;
			pq.push({-v[i].first.second, lt});
			ans[v[i].second] = lt;
		} else {
			pii tmp = pq.top();
			if (-tmp.first < v[i].first.first) {
				pq.pop();
				pq.push({-v[i].first.second, tmp.second});
				ans[v[i].second] = tmp.second;
			}

			else {
				lt++;
				pq.push({-v[i].first.second, lt});
				ans[v[i].second] = lt;
			}
		}

		cur = max(cur, int(pq.size()));
	}

	cout << cur << "\n";
	for (int i = 0; i < n; i++) { cout << ans[i] << " "; }
}