#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 13;

int ans[N];
map<int, vector<int>> mp;

int main()
{
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		mp.clear();
		memset(ans, 0, n * sizeof(ans[0]));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (mp[x].size() < k)
				mp[x].push_back(i);
		}
		int m = 0;
		for (auto e : mp) m += e.second.size();
		m -= m % k;
		int clo = 0;
		for (auto e : mp)
			for (auto i : e.second){
				ans[i] = ++clo;
				clo %= k;
				if (--m == 0) goto _output;
			}
        _output:
            for (int i = 0; i < n; i++)
                cout << ans[i] << ' ';
            cout << '\n';
	}

	return 0;
}