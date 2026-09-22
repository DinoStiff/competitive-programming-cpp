#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    int b = 0, e = n - 1;
    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    while (b < e) {
        if (w[b] + w[e] <= x) {
            n--, b++, e--;
        } else {
            e--;
        }
    }
    cout << n << endl;
}