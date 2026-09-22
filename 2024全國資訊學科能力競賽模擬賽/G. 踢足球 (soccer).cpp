#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 3002;

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
} goal[N], way[N];

istream& operator>>(istream& is, Vec &a){
    is>>a.x>>a.y;
    return is;
}

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

int ans = 0;

int main(){
    minji;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>way[i];
    }
    for(int i=0;i<m;i++){
        cin>>goal[i];
    }
    int cnt=0;
    sort(goal, goal+m);
    for(int i=0;i<m;i++){
        //cout<<goal[i];
        for(int j=i+1;j<m;j++){

            for(int k=0;k<n-1;k++){
                ans+=intersect(goal[i], goal[j], way[k], way[k+1]);
                // if(k>0)
                //     cnt+=between(goal[i], goal[j], way[k]);
            }
        }
    }
    cout<<ans-cnt<<'\n';
}