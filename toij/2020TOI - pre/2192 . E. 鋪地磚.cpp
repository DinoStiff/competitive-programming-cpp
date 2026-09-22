// 37% kmp 枚舉暴力解

#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

void build(vector<int> &fail, string q){
  int idx1=0, idx2=-1;
  fail.push_back(-1);
  while(idx1<q.size()){
    if(idx2==-1||q[idx1]==q[idx2]){
      idx1++, idx2++;
      fail.push_back(idx2);
    }
    else
      idx2=fail[idx2];
  }
}

int kmp(string s, string q){
  vector<int> fail;
  build(fail, q);

  int idx1=0, idx2=0, cnt=0;
  while(idx1<s.size()){
    if(idx2==-1||s[idx1]==q[idx2]){
      idx1++, idx2++;
      if(idx2==q.size()){
        idx2=fail[idx2];
        cnt++;
      }
    }
    else
      idx2=fail[idx2];
  }
  return cnt;
}
int ans=0, n, k;;
string c[N], s;
int val[N];

void dfs(int idx, string ss){
    if(idx==n){
        //cout<<ss<<'\n';
        int tmp = 0;
        for(int i=0;i<k;i++){
            tmp += kmp(ss, c[i])*val[i];
        }
        ans = max(tmp, ans);
        return;
    }
    if(s[idx]=='x'){
        dfs(idx+1, ss+'r');
        dfs(idx+1, ss+'g');
        dfs(idx+1, ss+'b');
    }
    else
        dfs(idx+1, ss+s[idx]);
    
}

int main(){
    star;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>c[i]>>val[i];
    }
    cin>>s;
    dfs(0, "");

    cout<<ans<<'\n';

}