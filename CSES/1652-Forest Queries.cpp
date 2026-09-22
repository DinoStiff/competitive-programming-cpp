#include <iostream>
using namespace std;
  
int n, m, x1, y1, x2, y2, pre[1005][1005];
char c;
  
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> c;
            if (c == '*') pre[i][j] = 1;
            pre[i][j] += pre[i][j-1];
            pre[i][j] += pre[i-1][j];
            pre[i][j] -= pre[i-1][j-1];
        }
    }
    for (int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1] << "\n";
    }
}