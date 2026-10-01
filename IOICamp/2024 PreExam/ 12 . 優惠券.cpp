#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e6+7;

struct coupon{
    ll id, l, r, amt, val;

    // bool operator < (coupon y){
    //     if(val == y.val)
    //         return id<y.id;
    //     return val>y.val;
    // }

    void print(){
        cout<<id<<' '<<l<<' '<<r<<' '<<amt<<' '<<val<<endl;
    }
};

bool cmp(coupon x, coupon y){
    if(x.val == y.val)
        return x.id<y.id;
    return x.val>y.val;
}

vector<coupon> v;
ll need[N], ans[N];

int main(){
    star;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        v.push_back({i, a, b, c, d});
        //v[i].print();
    }
    set <ll> day;
    for(int i=1;i<=m;i++){
        cin>>need[i];
        day.insert(i);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto &i:v){
        while(i.amt&&day.size()){
            auto pos = day.lower_bound(i.l);
            if(pos==day.end())
                break;
            if(*pos > i.r)
                break;
            if(i.amt >= need[*pos]){
                i.amt -= need[*pos];
                ans[*pos] += i.val * need[*pos];
                need[*pos] = 0;
                day.erase(pos);
            }
            else{
                ans[*pos] += i.val * i.amt;
                need[*pos] -= i.amt;
                i.amt = 0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}