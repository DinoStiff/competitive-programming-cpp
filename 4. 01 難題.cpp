#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n;

char g[12][12];
vector<pii> v;
bool ok=0;

bool check(){
    for(int i=0;i<n;i++){
        int a=0, b=0;
        for(int j=0;j<n;j++){
            if(g[i][j]=='0')
                a++;
            if(g[j][i]=='0')
                b++;
        }
        if(a!=n/2||b!=n/2)
            return 0;
    }
    return 1;
}

void solve(int idx){
    if(ok)
        return;
    if(idx==v.size()){
        if(check()){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<g[i][j]<<' ';
                }
                cout<<'\n';
            }
            ok=1;
        }
        return;
    }
    g[v[idx].first][v[idx].second]='0';
    solve(idx+1);
    g[v[idx].first][v[idx].second]='1';
    solve(idx+1);
}

int main(){
    minji;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            if(g[i][j]=='b')
                v.push_back({i, j});
        }
    }
    solve(0);
}