#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int ans = 1, x;

void find(){
    unsigned int i=2;
    int cnt = 0;
    int n = x;
    const int std=sqrt(n);
    while (n>1 && i<=pow(2,31)-1){
        if (i>std && x == n){
            break;
        }
        cnt = 0;
        while(n%i==0){
            n/=i;
            cnt++;
            if (cnt==2){
                x/=i*i;
                ans*=i;
                cnt = 0;
            }
        }
        i++;
    }
}

int main(){
    minji;
    cin>>x;
    find();
    if (ans==1) printf("sqrt(%d)",x);
    else if (x==1) printf("%d",ans);
    else printf("%d sqrt(%d)",ans,x);
}