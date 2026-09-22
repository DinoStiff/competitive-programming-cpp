#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main() {
	star;
	int k, m, n;
	cin >> k >> m >> n;
	vector<pii> p(k + m);
	for (int i = 0; i < k; i++){
		cin >> p[i].first >> p[i].second;
    }
	for (int i = k; i < k + m; i++) {
		cin >> p[i].first;
		p[i].second = -1;
	}
	sort(begin(p), end(p));
	vector<ll> val;
	int l = -1;
	ll sum = 0;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].second == -1) {
			if (l == -1) {
				val.push_back(sum);
			} else {
				ll cnt = 0;
				ll tmp = 0;
                int idx = l+1;
				for (int j = l + 1; j < i; j++) {
					while (idx < i && (p[idx].first - p[j].first) * 2 < p[i].first - p[l].first) {
						cnt += p[idx++].second;
					}
					tmp = max(tmp, cnt);
					cnt -= p[j].second;
				}
                if(2 * tmp >= sum){
                    val.push_back(tmp);
                    val.push_back(sum - tmp);
                }
			}
			l = i;
			sum = 0;
		} else {
			sum += p[i].second;
		}
	}
	val.push_back(sum);
	sort(rbegin(val), rend(val));
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ans += val[i];
    }
	cout << ans << '\n';
}