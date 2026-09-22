#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7, C = 1e6;

ll dp[N], s[N], f[N];

struct Tree{
    ll slp = 0, y_int = INF;
    Tree *L = nullptr, *R = nullptr;
    ll operator () (int x){
        return slp*x+y_int;
    }
}root;



void modify(ll m, ll k, int l, int r, Tree *seg){
    ll mid = (l+r)/2;
    if(m*mid+k<(*seg)(mid)){
        swap(seg->slp, m);
        swap(seg->y_int, k);
    }
    if(l==r)
        return;
    if(m>seg->slp){
        if(seg->L==nullptr)
            seg->L = new Tree;
        modify(m, k, l, mid, seg->L);
    }
    else{
        if(seg->R==nullptr)
            seg->R = new Tree;
        modify(m, k, mid+1, r, seg->R);
    }
}

ll query(ll k, int l, int r, Tree *seg){
    ll res=INF;
    if(k<l||k>r)
        return INF;
    if(l==r){
        return (*seg)(k);
    }
    int mid = (l+r)/2;
    if(k<=mid){
        if(seg->L!=nullptr)
            res = query(k, l, mid, seg->L);
        return min((*seg)(k), res);
    }
    else{
        if(seg->R!=nullptr)
            res = query(k, mid+1, r, seg->R);
        return min((*seg)(k), res);
    }
}

int main(){
    star;
    ll n;
    cin>>n>>f[0];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    modify(f[0], 0, 1, C, &root);
    for(int i=1;i<=n;i++){
        dp[i] = query(s[i], 1, C, &root);
        modify(f[i], dp[i], 1, C, &root);
    }
    cout<<dp[n]<<'\n';
}