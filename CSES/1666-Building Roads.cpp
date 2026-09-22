#include <bits/stdc++.h>
using namespace std;
  
int n, m, p[100005], a, b;
vector <pair<int, int> > v;
  
int f(int x){
    if (p[x] == x) return x;
    else return p[x] = f(p[x]);
}
  
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        p[i] = i;
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        if (f(a) != f(b)) p[f(a)] = p[f(b)];
    }
    for (int i = 2; i <= n; i++){
        if (f(1) != f(i)){
            v.push_back({f(1), f(i)});
            p[f(i)] = p[f(1)];
        }
    }
    cout << v.size() << "\n";
    for (auto i:v){
        cout << i.first << " " << i.second << "\n";
    }
}