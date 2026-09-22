#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    nice;
    int a, b, c;
    cin>>a>>b>>c;
    if(b>c){
        if((b<=a&&a<24)||(0<=a&&a<c))
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    else{
        if(b<=a&&a<c)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}