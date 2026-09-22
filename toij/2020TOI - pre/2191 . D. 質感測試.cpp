#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

struct vec{
    ll x, y, c;

    ll operator ^ (vec &b){
        return x*b.y-y*b.x;
    }
};

bool cmp(vec a, vec b){
    return (a^b) < 0LL;
}

vector<vec> v;

int main(){
    star;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        if (a < 0) a = -a, b = -b;
        else if (!a && b < 0) b = -b;
        v.push_back({a, b, c});
    }
    sort(all(v), cmp);
    vector<int> val;
    int sum = 0;
    for(int i=0;i<n;i++){
        int tmp = 0, j = i;
        while(j<n&&!(v[i]^v[j])){
            //cout<<v[j].x<<' '<<v[j].y<<' '<<v[j].c<<' ';
            tmp += v[j].c;
            //cout<<tmp<<'\n';
            j++;
        }
        i = j-1;
        val.push_back(tmp);
        sum+=tmp;
    }
    int tmp1 = 0, tmp2=0, mx = 0, mn=0;
    for(int i=0;i<val.size();i++){
        //cout<<val[i]<<' ';
        tmp1 += val[i];
        tmp2 += val[i];
        mx = max(mx, tmp1);
        mn = min(mn, tmp2);
        if (tmp1 < 0) tmp1 = 0;
        if (tmp2 > 0) tmp2 = 0;
    }
    cout<<max(mx, sum-mn)<<'\n';
}