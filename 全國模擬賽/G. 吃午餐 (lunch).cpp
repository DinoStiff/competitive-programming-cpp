#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<pair<int, int>> a(n);
  set<pair<int, int>> b;
  int fm=0, sm=0;
  for(int i=0;i<n;i++){
    cin>>a[i].first;
    fm = max(fm, a[i].first);
  }
  for(int i=0;i<n;i++){
    cin>>a[i].second;
    sm = max(sm, a[i].second);
  }
  sort(a.rbegin(), a.rend());
  int r, l, k;
  r = fm + sm;
  l = 2;
  for(int i=0;i<n;i++){
    cout<<a[i].first<<' ';
  }
  cout<<endl;
    for(int i=0;i<n;i++){
    cout<<a[i].second<<' ';
  }
  cout<<endl;
  while(l<r){
    b.clear();
    for(int i=0;i<n;i++){
      b.insert({a[i].second, i});
    }
    
    k = (l+r)/2;
    bool used[n], ok = 1;
    memset(used, 0, sizeof used);
    
    for(int i=0;i<n;i++){
      if(used[i]){
        continue;
      }
      cout << i <<' '<<a[i].first<<' '<<a[i].second<<" ";
      if(a[i].first+a[i].second > k){
        ok = 0;
        cout << "c\n";
        break;
      }
      int nb = k - a[i].first;
      b.erase({a[i].second, i});
      auto id = b.upper_bound({nb, n});
      if (id == b.end()){
        cout<<"out "<<i<<endl;
        ok = 0;
        break;
      }
      used[i] = 1;
      id = prev(id);
      used[(*id).second] = 1;
      cout<<(*id).second<<'\n';
      b.erase(id);
    }
    cout << l << ' ' << r << '\n'<<'\n';
    if(ok){
      r = k;
    }
    else{
      l = k+1;
    }
  }
  cout<<l<<'\n';
}