#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
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

ll abs2 (Vec a){
	return a.x*a.x+a.y*a.y;
}
double abs (Vec a){
	return sqrt(abs2(a));
}
int sign (ll a){
	return a==0? 0 : (a>0? 1:-1);
}
int ori (Vec a, Vec b, Vec c){
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



Vec proj(Vec a, Vec b){
	
}

int main(){
    nice;
    int n;
    cin>>n;
    Vec a, b, c;
    while(n--){
        cin>>a>>b>>c;
        int ans = ori(a, b, c);
        if(ans==1)
            cout<<"LEFT\n";
        else if(ans==0)
            cout<<"TOUCH\n";
        else
            cout<<"RIGHT\n";
    }
}