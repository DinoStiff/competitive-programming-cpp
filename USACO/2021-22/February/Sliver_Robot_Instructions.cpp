#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

struct vec{
    ll x, y, k;

    vec operator + (vec b){
        return {x+b.x, y+b.y, k+b.k};
    }

    vec operator - (vec b){
        return {x-b.x, y-b.y, k-b.k};
    }

    bool operator < (const vec &b) const {
        if(x==b.x){
            if(y==b.y)
                return k<b.k;
            return y<b.y;
        }
        return x<b.x;
    }

};

vector<vec> lft, rgt, com, tmp;
int n;
ll ex, ey;

void findall(int l, int r, vec sum){
    if(l>r){
        if(r==n/2-1)
            lft.push_back(sum);
        else
            rgt.push_back(sum);
        return;
    }
    findall(l+1, r, sum);
    findall(l+1, r, sum+com[l]);
}

int main(){
    star;
    cin>>n;
    cin>>ex>>ey;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        com.push_back({a, b, 1});
    }
    findall(0, n/2-1, {0, 0, 0});
    findall(n/2, n-1, {0, 0, 0});
    for(int i=1;i<=n;i++){
        ll ans=0;
        vec a = {ex, ey, i};
        for(auto i:rgt){
            tmp.push_back(a-i);
        }
        sort(all(tmp));
        for(auto i:lft){
            ans+=upper_bound(all(tmp), i)-lower_bound(all(tmp), i);
        }
        cout<<ans<<'\n';
        tmp.clear();
    }
}