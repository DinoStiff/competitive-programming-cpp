#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;

ll Pow(ll b, ll x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return b % MOD;
    ll tmp = Pow(b, x / 2);
    if (x % 2 == 0) {
        return (tmp * tmp) % MOD;
    }
    else {
        return (((tmp * tmp) % MOD) * b) % MOD;
    }
}

int main()
{
    ll n;
    cin>>n;
    ll a, b;
    while(n--){
        cin>>a>>b;
        cout << Pow(a, b) << "\n";
    }
}
