#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define good_luck ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    good_luck;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c>=a&&d<b){
        cout << "Yes" << '\n';
    }else{
        cout << "No" << '\n';
    }
}