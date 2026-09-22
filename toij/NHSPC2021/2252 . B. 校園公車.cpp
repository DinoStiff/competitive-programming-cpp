#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const double INF = 1e18;


struct pos{
    double x, y;
    void operator = (pos b){
        x=b.x;
        y=b.y;
    }
};

double dis(pos a, pos b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double area(pos a, pos b, pos c){
    return abs(a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x);
}

double solve(pos o, pos p, pos q){
    if (dis(o, p) + dis(p, q) < dis(o, q))
        return sqrt(dis(o, p));
    else if (dis(o, q) + dis(p, q) < dis(o, p))
        return sqrt(dis(o, q));
    else
        return area(o, p, q)/sqrt(dis(p, q));
}


int main(){
    nice;
    pos o;
    double ans = INF+0.0;
    int n;
    cin>>o.x>>o.y>>n;
    pos a, b;
    cin>>a.x>>a.y;
    for(int i=1;i<=n;i++){
        cin>>b.x>>b.y;
        ans=min(ans, solve(o, a, b));
        a=b;
    }
    cout << setprecision(16) << ans << endl;
}