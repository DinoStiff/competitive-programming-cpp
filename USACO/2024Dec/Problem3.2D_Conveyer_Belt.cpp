#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int MAXN = 1000;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool in_stack[MAXN][MAXN];
int N, Q;

// Directions corresponding to U, D, L, R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char directions[] = {'U', 'D', 'L', 'R'};

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

// Check for cycle using DFS
bool dfs(int r, int c) {
    if (!isValid(r, c) || grid[r][c] == '?') return false;
    if (visited[r][c]) {
        if (in_stack[r][c]) return true; // Found a cycle
        return false;
    }

    visited[r][c] = true;
    in_stack[r][c] = true;

    int dir_index = -1;
    for (int i = 0; i < 4; ++i) {
        if (directions[i] == grid[r][c]) {
            dir_index = i;
            break;
        }
    }

    int nr = r + dr[dir_index];
    int nc = c + dc[dir_index];
    if (dfs(nr, nc)) {
        in_stack[r][c] = false;
        return true;
    }

    in_stack[r][c] = false;
    return false;
}

// Count unusable cells
int countUnusable() {
    int unusable = 0;
    memset(visited, 0, sizeof(visited));
    memset(in_stack, 0, sizeof(in_stack));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] != '?' && !visited[i][j]) {
                if (dfs(i, j)) {
                    unusable++;
                }
            }
        }
    }
    return unusable;
}

int main() {
    cin >> N >> Q;
    memset(grid, '?', sizeof(grid));

    for (int i = 0; i < Q; ++i) {
        int ri, ci;
        char ti;
        cin >> ri >> ci >> ti;
        ri--; ci--; // Convert to 0-based indexing

        grid[ri][ci] = ti;
        cout << countUnusable() << endl;
    }

    return 0;
}
