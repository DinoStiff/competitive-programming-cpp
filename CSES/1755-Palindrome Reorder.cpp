#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    int n = s.length();
    string ans(n, ' ');

    int cnt[26] = {};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'A'] += 1;
    }
    int tmp = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 != 0) {
            tmp += 1;
        }
    }
    if (tmp > 1)
        return "NO SOLUTION";

    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (cnt[s[i] - 'A'] % 2 == 1) {
            ans[n / 2] = s[i];
            cnt[s[i] - 'A'] -= 1;
        }
        while (cnt[s[i] - 'A'] > 0) {
            ans[l++] = ans[r--] = s[i];
            cnt[s[i] - 'A'] -= 2;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout << solve(s) << endl;
    return 0;
}
