#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e12;
const int N = 1e5+7;

int n, d;
double a[N], b[N];

bool ok(double k){
    vector<double> v;
    for(int i=0;i<n;i++){
        v.push_back(a[i]-k*b[i]);
    }
    sort(v.rbegin(), v.rend());
    double sum=0;
    for(int i=0;i<d;i++){
        sum+=v[i];
    }
    return sum >= 0;
}

int main(){
    star;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    double l = 0, r = INF;
    for(int i=0;i<60;i++){
        double k = (l+r)/2;
        if(ok(k))
            l = k;
        else
            r = k;
    }
    cout<<fixed<<setprecision(9)<<l<<'\n';
}