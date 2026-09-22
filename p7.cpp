#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int countIslands(vector<vector<int>>& grid, int n, int m, int h) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int islandCount = 0;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] >= h) {
                islandCount++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (auto& dir : directions) {
                        int nx = x + dir[0], ny = y + dir[1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] >= h) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    return islandCount;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> grid(N, vector<int>(M));
        set<int> heights;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> grid[i][j];
                heights.insert(grid[i][j]);
            }
        }

        int maxIslands = 0;

        for (int h : heights) {
            maxIslands = max(maxIslands, countIslands(grid, N, M, h));
            maxIslands = max(maxIslands, countIslands(grid, N, M, h + 1));
        }

        cout << maxIslands << endl;
    }

    return 0;
}
