#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
const int mod = 998244353;
const int ma = 200005;
int a[ma];
int b[ma];
int cnt[ma];
vector<int> v[ma];
int win[ma];
bool vis[ma];
queue<int> bfs;
int toint(string s){
  int num = 0;
  for(int i = 0 ; i < 3 ; i ++){
    if(s[i] <= 'Z' && s[i] >= 'A'){
      num = num * 52 + s[i] - 'A';
    }
    else{
      num = num * 52 + s[i] - 'a' + 26;
    }
  }
  return num;
}
void solve(){
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    string s;
    cin >> s;
    a[i] = toint(s.substr(0, 3));
    b[i] = toint(s.substr(s.size() - 3));
    v[b[i]].push_back(a[i]);
    cnt[a[i]]++;
  }
  int total = 52 * 52 * 52;
  for(int i = 0 ; i < total ; i++){
    if(cnt[i] == 0){
      win[i] = -1;
      bfs.push(i);
      vis[i] = 1;
    }
  }
  while(bfs.size()){
    int x = bfs.front();
    bfs.pop();
    for(int i : v[x]){
      cnt[i]--;
      if(win[x] == -1 && vis[i] == 0){
        win[i] = 1;
        bfs.push(i);
        vis[i] = 1;
      }
      if(cnt[i] == 0 && vis[i] == 0){
        win[i] = -1;
        bfs.push(i);
        vis[i] = 1;
      }
    }
  }
  for(int i = 1 ; i <= n ; i++){
    if(win[b[i]] == -1) cout << "Takahashi" << '\n';
    else if(win[b[i]] == 1) cout << "Aoki" << '\n';
    else cout << "Draw" << '\n';
  }
}
  
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  solve();
}