#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> v;
    v.push_back("");
    for (int i = 0; i < n; i++) {
        int size = v.size();
        for (int j = size - 1; j >= 0; j--) {
            v.push_back(v[j]);
        }
        size *= 2;
        for (int j = 0; j < size; j++) {
            if (j < v.size() / 2) {
                v[j] += "0";
            } else {
                v[j] += "1";
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}