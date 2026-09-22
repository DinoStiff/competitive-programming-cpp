#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

struct Vec{
	double x, y;

    Vec(){
		x=0, y=0;
	}
	Vec(double a, double b){
		x=a, y=b;
	}
	Vec operator + (Vec b){
		return {x+b.x, y+b.y};
	}
	Vec operator - (Vec b){
		return {x-b.x, y-b.y};
	}
	double operator * (Vec b){
		return x*b.x+y*b.y;
	}
	Vec operator * (double b){
		return {x*b, y*b};
	}
    Vec operator / (double b){
		return {x/b, y/b};
	}
	double operator ^ (Vec b){
		return x*b.y-y*b.x;
	}
};

istream& operator >> (istream& is, Vec &a){
    is>>a.x>>a.y;
    return is;
}

ostream& operator << (ostream& os, Vec &a){
    os<<a.x<<' '<<a.y;
    return os;
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

double search(Vec a, Vec b){
    Vec l(-1e18, 0.), r(1e18, 0.);
    if(a.x<b.x){
        l=Vec(b.x, 0);
        
    }
    if(a.x>b.x){
        r=Vec(b.x, 0);
    }
   
    for(int i=0;i<100;i++){
        Vec m = (l+r)/2.;
        //cout<<m<<'\n';
        if(((b-a)^(m-a))>=0){
            r=m;
        }
        else{
            l=m;
        }
    }
    //cout<<'\n';
    return l.x;
}

double search2(Vec a, Vec b){
    Vec l(-1e16, 0.), r(1e16, 0.);
    if(a.x<b.x){
        l=Vec(b.x, 0);
        
    }
    if(a.x>b.x){
        r=Vec(b.x, 0);
    }
   
    for(int i=0;i<55;i++){
        Vec m = (l+r)/2.;
        //cout<<m<<'\n';
        if(((b-a)^(m-a))>=0){
            r=m;
        }
        else{
            l=m;
        }
    }
    //cout<<'\n';
    return l.x;
}


vector<pair<double, double>> v;

int main(){
    minji;
    ll n;
    Vec s;
    cin>>n>>s;
    double ans = 0;
    if(n<=100){
        for(int i=0;i<n;i++){
            ll a, b, c;
            cin>>a>>b>>c;
            Vec cl(a, c), cr(b, c);
            v.push_back({search(s, cl), search(s, cr)});

        }
    }
    else{
        for(int i=0;i<n;i++){
            ll a, b, c;
            cin>>a>>b>>c;
            Vec cl(a, c), cr(b, c);
            v.push_back({search2(s, cl), search2(s, cr)});

        }
    }
    sort(all(v));
    double l, r;
    for(int i=0;i<v.size();i++){
        l=v[i].first;
        r=v[i].second;
        int k=i+1;
        while(v[k].first<=r&&k<v.size()){
            r=max(r, v[k].second);
            k++;
        }
        i=k-1;
        ans+=r-l;
        //cout<<l<<' '<<r<<'\n';
    }
    cout<<fixed<<setprecision(7)<<ans<<'\n';


}