#include <bits/stdc++.h>
using namespace std;

namespace str {

vector<int> kmp(const string &s) {
	int n = s.size();
	vector<int> dp(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[j] != s[i]) { j = dp[j - 1]; }
		if (s[i] == s[j]) { j++; }
		dp[i] = j;
	}
	return dp;
}
}  // namespace str

int main() {
	string a, b;
	cin >> b >> a;
	string s = a + '#' + b;
	vector<int> v = str::kmp(s);
	int ans = 0;
	for (int l : v) {
		if (l == a.size()) { ans++; }
	}
	cout << ans << '\n';
}