#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> st, en;
    for(int i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        st.push_back(a);
        en.push_back(b);
    }
    sort(st.begin(), st.end());
    sort(en.begin(), en.end());
    ll cur = 0;
    ll ans = 0;
    ll a = 0, b = 0;
    while(a < st.size() && b < en.size()){
        if(st[a] < en[b]){
            ans = max(ans, cur+1);
            cur++;
            a++;
        } else if (st[a] > en[b]){
            cur--;
            b++;
        } else {
            a++; b++;
        }
    }
    cout << ans << '\n';
}