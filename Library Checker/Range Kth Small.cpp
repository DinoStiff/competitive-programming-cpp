#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define nice ios::sync_with_stdio(false), cin.tie(0)

const int INF = 1e18;
const int maxn = 5e5 + 5;
const int N = 998244353;
int ans[maxn];
int n, q;

struct node{
	int l, r, k, id;
	node(){}
	node(int L, int R, int K, int ID) : l(L), r(R), k(K), id(ID){}
};

void solve(vector<pii> a, vector<node> qry, int l, int r){
	if(qry.empty()) return;
	int m = (l + r) / 2;
	if(l == r){
		for(auto [ll, rr, k, id] : qry) ans[id] = l;
		return;
	}
	vector<int> id;
	for(auto [val, idx] : a) if(val <= m) id.push_back(idx);
	vector<pii> a1, a2;
	vector<node> q1, q2;
	for(int i = 0; i < qry.size(); i++){
		auto [l, r, k, idx] = qry[i];
		int cnt = upper_bound(id.begin(), id.end(), r) - lower_bound(id.begin(), id.end(), l);
		if(cnt < k) qry[i].k -= cnt, q2.push_back(qry[i]);
		else q1.push_back(qry[i]);
	}
	for(auto [val, idx] : a){
		if(val <= m) a1.push_back({val, idx});
		else a2.push_back({val, idx});
	}
	solve(a1, q1, l, m);
	solve(a2, q2, m + 1, r);
}

signed main(){
	nice;
	cin>>n>>q;
	vector<pii> a(n);
	for(int i = 0; i < n; i++) cin>>a[i].first, a[i].second = i;
	vector<node> qry;
	for(int i = 0; i < q; i++){
		int l, r, k;
		cin>>l>>r>>k;
		r--, k++;
		qry.push_back(node(l, r, k, i));
	}
	solve(a, qry, 0, INF);
	for(int i = 0; i < q; i++) cout<<ans[i]<<'\n';
}