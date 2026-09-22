#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lim=100000;
const ll All=1e15;
int n,m;
#define N 100010
#define V 2000010
int hd[N],v[N<<1],nxt[N<<1],tot=0;
int a[N],b[N];
ll dp[N];
void add_edge(int s,int e){
    tot++;v[tot]=e;nxt[tot]=hd[s];hd[s]=tot;
    tot++;v[tot]=s;nxt[tot]=hd[e];hd[e]=tot;
}
struct Line{
    int k;
    ll b;
    ll y(int x){return 1ll*k*x+b;}
};
struct Node{
    Line ans;
    int son[2]; 
    int siz;
}tr[V];
int root[N],cnt=0;
void update(int &k,int l,int r,Line pos){
    if(!k){
        k=++cnt;
        tr[k].ans=pos;
        tr[k].siz=1;
        return;
    }
    ll p1=tr[k].ans.y(l),p2=tr[k].ans.y(r);
    p1=-p1;p2=-p2;
    ll c1=pos.y(l),c2=pos.y(r);
    c1=-c1;c2=-c2;
    if(c1>p1&&c2>p2){
        tr[k].ans=pos;
        return;
    }
    if(c1<=p1&&c2<=p2)return;
    double at=1.0*(tr[k].ans.b-pos.b)/(pos.k-tr[k].ans.k);
    int mid=(l+r)>>1;
    if(c1>p1){
        if(at>mid){
            update(tr[k].son[1],mid+1,r,tr[k].ans);
            tr[k].ans=pos;
        }else update(tr[k].son[0],l,mid,pos);
    }else{
        if(at>mid)update(tr[k].son[1],mid+1,r,pos);
        else{
           update(tr[k].son[0],l,mid,tr[k].ans);
           tr[k].ans=pos;
        }
    }
    tr[k].siz=tr[tr[k].son[0]].siz+tr[tr[k].son[1]].siz+1;
}
void merge(int &k,int u,int l,int r){
    if(!u)return;
    update(k,l,r,tr[u].ans);
    int mid=(l+r)>>1;
    if(tr[u].son[0])merge(tr[k].son[0],tr[u].son[0],l,mid);
    if(tr[u].son[1])merge(tr[k].son[1],tr[u].son[1],mid+1,r);
}
ll Query(int k,int l,int r,int pos){
    if(!k)return All;
    ll res=tr[k].ans.y(pos);
    int mid=(l+r)>>1;
    if(l==r)return res;
    if(pos<=mid)return min(res,Query(tr[k].son[0],l,mid,pos));
    else return min(res,Query(tr[k].son[1],mid+1,r,pos));
}
int seq[N],dfk=0; 
void dfs(int u,int f){
    seq[++dfk]=u;
    for(int i=hd[u];i;i=nxt[i])
        if(v[i]^f){
            dfs(v[i],u);
            if(tr[root[u]].siz<tr[root[v[i]]].siz)swap(root[u],root[v[i]]);
            merge(root[u],root[v[i]],0,2*lim);
    }
    if(!root[u])dp[u]=0;
    else dp[u]=Query(root[u],0,2*lim,a[u]+lim);
    update(root[u],0,2*lim,(Line){b[u],dp[u]-1ll*b[u]*lim});
}
  
inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
  
int main(){
    rd(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>> b[i];
    int s,e;
    for(int i=1;i<n;i++){
        cin>>s>>e;
        add_edge(s,e);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)printf("%lld ",dp[i]);
    return 0;
}
