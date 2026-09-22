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
    int n, l, r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a < l) {
            cout<<l<<' ';
        } else if (a > r) {
            cout<<r<<' ';
        } else {
            cout<<a<<' ';
        }
    }
    cout<<'\n';
}