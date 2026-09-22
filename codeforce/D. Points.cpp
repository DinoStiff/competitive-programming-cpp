#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e9;
const int N = 4e5+7;


struct Query{
	int op, x, y;
}q[N];

int tmp[N], cnt, maxn[N<<2];
set<int> s[N];
void pushup(int x){
	maxn[x]=max(maxn[x*2], maxn[x*2+1]);
}
void update(int idx, int l, int r, int x, int val){
	if(l==r){
		maxn[idx] = max(maxn[idx], val);
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(idx*2, l, mid, x, val);
	else
		update(idx*2+1, mid+1, r, x, val);
	pushup(idx);
}

void modify(int idx, int l, int r, int x, int val){
	if(l==r){
		maxn[idx]=val;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)
		modify(idx*2, l, mid, x, val);
	else
		modify(idx*2+1, mid+1, r, x, val);
	pushup(idx);
}

int query(int idx, int l, int r, int x, int y){
	if(l==r){
		if(maxn[idx]>y);
			return l; 
		return -1;
	}
	int mid=l+r>>1, res=-1;
	if(x<=mid&&maxn[idx*2]>y)
		res=query(idx*2, l, mid, x, y);
	if(res!=-1)
		return res;
	if(maxn[idx*2+1]>y)
		res=query(idx*2+1, mid+1, r, x, y);
	return res;
}

int main(){
    minji;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string ss;
		int x, y;
		cin>>ss>>x>>y;
		if(ss=="add")
			q[i].op=1, q[i].x=x, q[i].y=y;
		else if(ss=="remove")
			q[i].op=2, q[i].x=x, q[i].y=y;
		else
			q[i].op=3, q[i].x=x, q[i].y=y;
		tmp[++cnt]=x, tmp[++cnt]=y;
	}
	sort(tmp+1, tmp+1+cnt);
	int len=unique(tmp+1, tmp+1+cnt)-(tmp+1);
	for(int i=1;i<=n;i++){
		q[i].x=lower_bound(tmp+1, tmp+1+len, q[i].x)-tmp;
		q[i].y=lower_bound(tmp+1, tmp+1+len, q[i].y)-tmp;
	}
	for(int i=1;i<=n;i++){
		if(q[i].op==1){
			s[q[i].x].insert(q[i].y);
			update(1, 1, len, q[i].x, q[i].y);
		}
		else if(q[i].op==2){
			s[q[i].x].erase(s[q[i].x].find(q[i].y));
			if(s[q[i].x].empty())
				modify(1, 1, len, q[i].x, 0);
			else
				modify(1, 1, len, q[i].x, *--s[q[i].x].end());
		}
		else{
			int pos=query(1, 1, len, q[i].x+1, q[i].y);
			if(pos==-1)
				cout<<"-1\n";
			else
				cout<<tmp[pos]<<" "<<tmp[*s[pos].upper_bound(q[i].y)]<<"\n";
		}
	}
}
