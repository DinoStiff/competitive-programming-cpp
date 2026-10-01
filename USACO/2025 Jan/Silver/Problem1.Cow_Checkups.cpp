#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N), b(N), pos(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    return 0;
}
