#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAX_VERTICES = 500;

int main() {
    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        unordered_map<int, unordered_set<int>> graph;
        queue<pair<int, int>> bfsQueue; // Queue to store vertex and distance pair
        bfsQueue.push({1, 0});
        unordered_set<int> discovered; // To keep track of visited vertices
        discovered.insert(1);

        bool found = false;

        while (!bfsQueue.empty() && !found) {
            auto [current, dist] = bfsQueue.front();
            bfsQueue.pop();

            // If all neighbors are not discovered, scan them
            while (graph[current].size() < 3) {
                cout << "SCAN " << current << endl;
                cout.flush();
                int neighbor;
                cin >> neighbor;
                if (!graph[current].count(neighbor)) {
                    graph[current].insert(neighbor);
                    graph[neighbor].insert(current);
                }
            }

            // Explore all neighbors
            for (int neighbor : graph[current]) {
                if (!discovered.count(neighbor)) {
                    discovered.insert(neighbor);
                    bfsQueue.push({neighbor, dist + 1});
                    if (neighbor == 500) {
                        cout << "SUBMIT " << dist + 1 << endl;
                        cout.flush();
                        string response;
                        cin >> response;
                        if (response == "CORRECT") {
                            found = true;
                            break;
                        } else {
                            return 0; // If wrong answer received, terminate
                        }
                    }
                }
            }
        }
    }
    return 0;
}
