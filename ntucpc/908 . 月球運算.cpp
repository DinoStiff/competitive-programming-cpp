#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e5+7;

string arr[N];

string Max(string a, string b){
    if(a.size()>b.size())
        swap(a, b);
    reverse(all(a));
    while(a.size()!=b.size()){
        a+='0';
    }
    reverse(all(a));
    for(int i=0;i<a.size();i++){
        a[i]=max(a[i], b[i]);
    }
    return a;
}

string findans(int l, int r){
    string ans = arr[l];
    for(int i=l+1;i<=r;i++){
        ans=Max(ans, arr[i]);
    }
    return ans;
}

void add(int l, int r, string v){
    for(int i=l;i<=r;i++){
        arr[i]=Max(v, arr[i]);
    }
}

void same(int l, int r, string v){
    for(int i=l;i<=r;i++){
        arr[i]=v;
    }
}

int main(){
    minji;
    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    while(q--){
        int o, l , r;
        cin>>o>>l>>r;
        if(o==1){
            cout<<findans(l, r)<<'\n';
        }
        else if(o==2){
            string s;
            cin>>s;
            add(l, r, s);
        }
        else{
            string s;
            cin>>s;
            same(l, r, s);
        }
    }
}