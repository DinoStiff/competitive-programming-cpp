#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
  int n, x, ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    pq.push(x);
  }
  while(pq.size()>1){
    x=pq.top();
    pq.pop();
    x+=pq.top();
    pq.pop();
    pq.push(x);
    ans+=x;
  }
  cout<<ans<<'\n';
} 