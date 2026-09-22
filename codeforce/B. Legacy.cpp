#include <bits/stdc++.h>
typedef long long ll;
const int maxn=100005, maxm=300005;
int n, m, s, cnt, rt1, rt2;
int total, head[maxm], lft[maxm], rgt[maxm], to[maxn*20], nxt[maxn*20], len[maxn*20];
using namespace std;
void add(int u, int v, int w){
	to[++total]=v;
	nxt[total]=head[u];
	head[u]=total;
	len[total]=w;
}
void build1(int&u, int l, int r){
	if(l==r){
		u=l;
		return;
	}
	u=++cnt;
	int m=(l+r)>>1;
	build1(lft[u], l, m);
	build1(rgt[u], m+1, r);
	add(u, lft[u], 0);
	add(u, rgt[u], 0);
}
void build2(int&u, int l, int r){
	if(l==r){
		u=l;
		return;
	}
	u=++cnt;
	int m=(l+r)>>1;
	build2(lft[u], l, m);
	build2(rgt[u], m+1, r);
	add(lft[u], u, 0);
	add(rgt[u], u, 0);
}
int ql, qr;
void update(int x, int l, int r, int u, int w, int type){
	if(ql<=l&&r<=qr){
		type==2?add(u, x, w):add(x, u, w);
		return;
	}
	int m=(l+r)>>1;
	if(ql<=m)update(lft[x], l, m, u, w, type);
	if(qr>m)update(rgt[x], m+1, r, u, w, type);
}
const ll inf=0x3f3f3f3f3f3f3f3f;
bool inq[maxm];
ll dis[maxm];
std::priority_queue<std::pair<long long, int> >q;
void dijkstra(int s){
	memset(dis, 0x3f, sizeof(dis));
	dis[s]=0;
	q.push(std::make_pair(0, s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(inq[u])continue;
		inq[u]=true;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i], w=len[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({-dis[v], v});
			}
		}
	}
}
int main(){
	cin>>n>>m>>s;
	cnt=n;
	build1(rt1, 1, n);
	build2(rt2, 1, n);
	int op, u, v, w;
	while(m--){
		cin>>op;
		if(op==1){
			cin>>u>>v>>w;
			add(u, v, w);
		}else{
            cin>>u>>ql>>qr>>w;
			update(op==2? rt1:rt2, 1, n, u, w, op);
		}
	}
	dijkstra(s);
	for(int i=1;i<=n;i++)
        cout << (dis[i]<inf?dis[i]:-1ll) << ' ';
	return 0;
}