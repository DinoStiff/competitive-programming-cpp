#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+7;

bool vis[N];
char ans[N];
int in[N], rt[N];
vector<int> ord, g1[N], g2[N], grp[N], scc[N];

int flip(int x){
    return (x&1 ? x+1 : x-1);
}

void add_edge(char c1, int a, char c2, int b){
    a = 2*a - (c1 == '-');
    b = 2*b - (c2 == '-');
    g1[flip(a)].push_back(b);
    g1[flip(b)].push_back(a);
    g2[a].push_back(flip(b));
    g2[b].push_back(flip(a));
}

void dfs1(int x){
    vis[x] = 1;
    for(int v : g1[x])
        if(!vis[v])
            dfs1(v);
    ord.push_back(x);
}

void dfs2(int x, int k){
    vis[x] = 1;
    rt[x] = k;
    grp[k].push_back(x);
    for(int v : g2[x])
        if(!vis[v])
            dfs2(v, k);
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        char c1, c2;
        int a, b;
        cin>>c1>>a>>c2>>b;
        add_edge(c1, a, c2, b);
    }

    for(int i = 1; i <= 2*m; i++)
        if(!vis[i])
            dfs1(i);

    memset(vis, 0, sizeof vis);
    reverse(ord.begin(), ord.end());
    int k = 1;
    for(int i : ord){
        if(!vis[i]){
            dfs2(i, k);
            k++;
        }
    }

    for(int i = 1; i <= m; i++){
        if(rt[2*i] == rt[2*i-1]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    for(int i = 1; i <= 2*m; i++){
        for(int j : g1[i]){
            if(rt[i] != rt[j]){
                scc[rt[i]].push_back(rt[j]);
                in[rt[j]]++;
            }
        }
    }

    queue<int> q;
    ord.clear();
    for(int i = 1; i <= k; i++){
        if(in[i] == 0){
            ord.push_back(i);
            q.push(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i : scc[x]){
            in[i]--;
            if(in[i] == 0){
                ord.push_back(i);
                q.push(i);
            }
        }
    }

    memset(vis, 0, sizeof vis);
    reverse(ord.begin(), ord.end());
    for(int k : ord){
        for(int i : grp[k]){
            int tmp = (i+1)/2;
            if(!vis[tmp]){
                ans[tmp] = (i&1 ? '-' : '+');
                vis[tmp] = 1;
            }
        }
    }

    for(int i = 1; i <= m; i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
}