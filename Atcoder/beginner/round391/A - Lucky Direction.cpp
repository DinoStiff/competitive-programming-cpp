#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    string s;
	cin>>s;
	if (s=="N"){
		cout<<"S";
	}
	if (s=="E"){
		cout<<"W";
	}
	if (s=="S"){
		cout<<"N";
	}
	if (s=="W"){
		cout<<"E";
	}
	if (s=="NE"){
		cout<<"SW";
	}
	if (s=="NW"){
		cout<<"SE";
	}
	if (s=="SE"){
		cout<<"NW";
	}
	if (s=="SW"){
		cout<<"NE";
	}
	return 0;

}