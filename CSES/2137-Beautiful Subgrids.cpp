#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 3007;

ll ans;
bitset<N> res[N];

int f(int x){
    return x*(x-1);
}

int main(){
    nice;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>res[i];
    }
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            ans += f((res[i]&res[j]).count());
    cout << (ans>>1);
}