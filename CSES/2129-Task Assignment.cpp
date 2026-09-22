#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9;
const int N = 407;

int n;
vector<int> g[N];
int w[N][N], a[N], b[N], useda[N], usedb[N], match[N];

bool dfs(int x, int tmp){
    for (int i:v[x]){
        if (!match[i]){
            match[i] = x;
            return 1;
        }
        else if (used[i]==tmp) continue;
        else{
            used[i] = tmp;
            if (dfs(match[i], tmp)){
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
  

int main(){
    nice;
    cin>>n;
    int tmp=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            w[i][j]=x;
        }
        b[N]=INF;
    }
}
