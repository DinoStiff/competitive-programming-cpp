#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

struct Bit{
    vector<ll> arr;
    int size(){
        return arr.size();
    }
    void resize(int n, ll val){
        arr.resize(n, val);
    }
    void modify(int k, ll val){
        for(int i=k;i<=arr.size();i+=i&-i){
            arr[i]+=val;
        }
    }
    ll query(int k){
        ll sum=0;
        for(int i=k;i>0;i-=i&-i){
            sum+=arr[i];
        }
        return sum;
    }
};

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


Vec proj(Vec a, Vec b){
	
}

struct Seg{

    
};

struct DSU{
    int p[N];
    ll amt[N];
    int f(int k){
        return p[k]==k? k:p[k]=f(p[k]);
    }
    void merge(int x, int y){
        int a=f(x), b=f(y);
        if(amt[a]<amt[b]){
            swap(a, b);
        }
        p[b]=a;
        amt[a]+=amt[b];
    }
}



int main(){
    star;
}