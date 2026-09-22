#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int m, n, dn, i, j, pi, pj, p[4000], pos[4000][5];
tuple<long long, int, int> d[8000000];
long long tol, ptol;

int find(int i)
{
    p[i] = (i == p[i])? i : find(p[i]);
    return p[i];
}
int main(){
   minji;

    cin >> m >> n;			// 維度 dim、點數 n 
    for(int i = 0; i < n; ++i)
    {
        p[i] = i;
        for(int j = 0; j < m; ++j)    cin >> pos[i][j];
        for(int j = i-1; j >= 0; --j)
        {
            tol = 0;
            for(int k = 0; k < m; ++k)    tol += abs(pos[i][k] - pos[j][k]);
            d[dn++] = make_tuple(tol, i, j);
        }
    }
    sort(d, d + dn);

    tie(ptol, i, j) = d[0];
    pi = find(i), pj = find(j);
    
    for(int k = n-1, di = 1; k > 0 && di < dn; --k, ++di)
    {
        p[pi] = pj;
        while(di < dn)
        {
            tie(tol, i, j) = d[di];
            pi = find(i), pj = find(j);
            if(pi != pj)    break;
            ++di;
        }
        
        if(tol == ptol)
        {
            cout << k + 1 << "\n";
            return 0;
        }
        ptol = tol;
    }
}