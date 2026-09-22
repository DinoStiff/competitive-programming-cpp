#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> queries(T);
    int maxN = 0;

    for (int i = 0; i < T; i++) {
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    vector<pii> addresses(maxN + 1);
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    set<pii> visited;

    // Initial house
    pq.push({2, {1, 1}});
    visited.insert({1, 1});

    // Addressing starts from 1
    int currentAddress = 1;
    addresses[currentAddress] = {1, 1}; // Address 1 is at (1, 1)

    while (currentAddress < maxN) {
        pipii top = pq.top();
        pq.pop();
        int dist = top.first;
        int x = top.second.first;
        int y = top.second.second;

        // Generate the next potential houses from (x, y)
        vector<pii> nextPoints = {{x + 1, y}, {x, y + 1}};
        for (auto &p : nextPoints) {
            if (visited.count(p) == 0 && gcd(p.first, p.second) == 1) {
                visited.insert(p);
                pq.push({p.first + p.second, p});
                currentAddress++;
                if (currentAddress <= maxN) {
                    addresses[currentAddress] = p;
                }
            }
        }
    }

    // Output results for each query
    for (int i = 0; i < T; i++) {
        pii res = addresses[queries[i]];
        cout << res.first << " " << res.second << "\n";
    }

    return 0;
}
