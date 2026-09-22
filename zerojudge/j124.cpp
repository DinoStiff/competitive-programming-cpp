#include <bits/stdc++.h>
using namespace std;

int n, idx, a[1000005];
long long ans;

void f(int x) {
  int chi = 2 + (x % 2);
  for (int i = 0; i < chi; i++) {
    int nxt = a[idx];
    idx++;
    if (nxt == 0)
      continue;
    ans += abs(x - nxt);
    f(nxt);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin, s);
  stringstream ss;
  ss << s;
  while (ss >> s) {
    a[n] = stoi(s);
    n++;
  }
  idx++;
  f(a[0]);
  cout << ans << "\n";
}