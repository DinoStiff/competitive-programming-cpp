#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }

	long long cnt = 0;
	long long ans = 0;
	map<long long, int> mp;
	mp[0] = 1;
	for (int i : v) {
		cnt += i;
		ans += mp[cnt - x];
		mp[cnt]++;
	}
	cout << ans << endl;
}