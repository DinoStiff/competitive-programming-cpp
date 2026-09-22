#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF  =  1e18;
const int N = 2e5+7;


int p[100000], dsu[100000];
int n, m, a, b, o, ans = 0;

int find(int a)
{
    int res = p[a];
    if (a != res) {
        p[a] = find(res);
        dsu[a] = (dsu[a]+dsu[res])%3;   
        return p[a];
    }
    else
        return res;
}
int main(){
    minji;
    cin>>n>>m;
    for (int i = 1;i <= n;i++){
        p[i] = i;
        dsu[i] = 0;
    }
    for (int i = 1;i <= m;i++){
        cin>>o>>a>>b;
        if ((a > n||b > n)||(o == 2 && a == b)) {
            ans++;
            continue;
        }
        if (o == 1) {
            int p1 = find(a), p2 = find(b);
            if (p1 == p2 && dsu[a] != dsu[b]){
                ans++; continue;
            } 
            else if(p1 != p2){
                p[p1] = p2; dsu[p1] = (3-dsu[a]+dsu[b])%3;
            }
        }
        if (o == 2)  {
            int p1 = find(a), p2 = find(b);
            if (p1 == p2) {
                int tmp = (dsu[a]-dsu[b]+3)%3;
                if (tmp != 1) {
                    ans++;
                    continue;
                }
            }
            else {
                int p1 = find(a), p2 = find(b);
                p[p1] = p2;
                dsu[p1] = (3-dsu[a]+dsu[b]+1)%3;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}