#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 7;
 
struct tree {
  int f = 0, s = 0, ff = 0;
  tree operator+(tree x) { return {f + x.f, s + x.s, ff}; }
 
  tree tmax(tree x, int idx, int p) {
    if (x.ff != idx) {
      if (x.f > f)
        return {x.f, f, p};
      else
        return {f, max(x.f, s), ff};
    } else {
      if (x.s > f)
        return {x.s, f, p};
      else
        return {f, max(x.s, s), ff};
    }
  }
 
  int sum() { return f + s; }
  void pt(){
    cout<<f<<' '<<s<<' '<<ff<<endl;
  }
} node[N], one = {1, 1, 0};
 
vector<int> v[N];
 
void dfs(int idx, int p) {
  for (int i : v[idx]) {
    if (i != p) {
      dfs(i, idx);
      node[idx] = node[idx].tmax(node[i] + one, idx, i);
    }
  }
}
 
void dfs2(int idx, int p) {
  //cout<<idx<<":\n";
  //node[idx].pt();
  node[idx] = node[idx].tmax(node[p]+one, idx, p);
  //node[idx].pt();
  //cout<<endl;
  for (int i : v[idx]) {
    if (i != p) {
      dfs2(i, idx);
    }
  }
}
 
int main() {
  int n, a, b;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    node[a].ff = a;
    node[b].ff = b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
 
  dfs(1, 0);
  dfs2(1, 0);
 
  for (int i = 1; i <= n; i++) {
    cout << node[i].f << ' ';
  }
  cout << endl;
}