#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp = 2;

    if (n == 2 || n == 3) {
      cout << "NO SOLUTION";
      return 0;
    }

    while(tmp <= n) {
      cout << tmp << " ";
      tmp += 2;
    }

    tmp = 1;

    while(tmp <= n) {
      cout << tmp << " ";
      tmp += 2;
    }

    return 0;
}