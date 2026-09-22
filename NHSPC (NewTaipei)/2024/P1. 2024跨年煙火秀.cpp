#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int M, d1, h1, m1, s1;
    int d2=62, h2=0, m2=0, s2=0;
    cin >> M >> d1 >> h1 >> m1 >> s1;
    if(M==12)
        d1+=30;
    if(s2-s1<0){
        s2=60+s2-s1;
        m2--;
    }
    if(m2-m1<0){
        m2=60+m2-m1;
        h2--;
    }
    if(h2-h1<0){
        h2=24+h2-h1;
        d2--;
    }
    d2-=d1;
    cout<<d2<<' '<<h2<<' '<<m2<<' '<<s2<<'\n';
}