#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, l, r, k;
string s, t;
char cl, cr;

int main(){ 
    minji;
    cin >> s;
    n = s.length();
    if(n%2 == 0)
        cl = s[n/2-1], cr = s[n/2], s.erase(n/2-1, 2);
    else
        cl = cr = s[n/2], s.erase(n/2, 1);
    s.insert(0, 1, cl);
    s.insert(s.end(), 1, cr);
    
    l = 0, r = s.length()-1;
    for(char c: s){
        if(c%2 == 0)
            t.push_back(s[r--]);
        else
            t.push_back(s[l++]);
    }
    
    for(int i = 0; i < 4; ++i)  k += (s[i]%2)^(t[i]%2);
    for(char c: t)  cout << char(c+k);
    cout << "\n";
}