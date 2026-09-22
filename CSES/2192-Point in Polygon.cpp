#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

struct Vec{
	ll x, y;

    Vec(){
		x=0, y=0;
	}
	Vec(ll a, ll b){
		x=a, y=b;
	}
	Vec operator + (Vec b){
		return {x+b.x, y+b.y};
	}
	Vec operator - (Vec b){
		return {x-b.x, y-b.y};
	}
	ll operator * (Vec b){
		return x*b.x+y*b.y;
	}
	Vec operator * (ll b){
		return {x*b, y*b};
	}
    Vec operator / (ll b){
		return {x/b, y/b};
	}
	ll operator ^ (Vec b){
		return x*b.y-y*b.x;
	}
};

istream& operator>>(istream& is, Vec &a){
    is>>a.x>>a.y;
    return is;
}

ostream& operator<<(ostream& os, Vec &a){
    os<<a.x<<a.y;
    return os;
}

ll abs2 (Vec a){
	return a.x*a.x+a.y*a.y;
}
double abs (Vec a){
	return sqrt(abs2(a));
}
ll sign (ll a){
	return a==0? 0 : (a>0? 1:-1);
}
ll ori (Vec a, Vec b, Vec c){
	return sign((b-a)^(c-a));
}
bool between(Vec a, Vec b, Vec c){
	return ori(a, b, c)? 0:((c-a)*(c-b)<=0? 1:0);
}
bool intersect(Vec a, Vec b, Vec c, Vec d){
    int x = ori(a, b, c);
    int y = ori(a, b, d);
    int z = ori(c, d, a);
    int w = ori(c, d, b);
    if(x!=y&&z!=w)
        return 1;
    if(between(a, b, c)||between(a, b, d)||between(c, d, a)||between(c, d, b))
        return 1;
    return 0;
}


int main(){
    minji;
    int n, m;
    cin>>n>>m;
    vector<Vec> v(n);
    Vec ini(1, 2e9+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    Vec q;
    while(m--){
        int cnt=0;
        bool ok=0;
        cin>>q;
        for(int i=0;i<n;i++){
            if(intersect(q, q+ini, v[i], v[(i+1)%n]))
                cnt++;
            if(between(v[i], v[(i+1)%n], q))
                ok=1;
        }
        if(ok){
            cout<<"BOUNDARY\n";
            continue;
        }
        if(cnt&1)
            cout<<"INSIDE\n";
        else
            cout<<"OUTSIDE\n";
    }
}
