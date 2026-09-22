#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define strawberry ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18+7;
const int N = 1e5+5, C = 1e9+2;
bitset<N> bt;
vector<int> vx,vy,side[2*N];
int x1[N], x2[N], Y1[N], y2[N], val[N],n,m;
struct Node{
    int val,tag;
}seg[11*N];

void pull(int idx){
    seg[idx].val = max(seg[idx*2].val,seg[idx*2+1].val);
}

void push(int idx){
    if(seg[idx].tag == 0)return;
    seg[idx*2].val += seg[idx].tag;
    seg[idx*2].tag += seg[idx].tag;
    seg[idx*2+1].val += seg[idx].tag;
    seg[idx*2+1].tag += seg[idx].tag;
    seg[idx].tag = 0;
}
void update(int l,int r,int ql,int qr,int k,int idx){
    int mid = (l+r)/2;
    if(r < ql || l > qr)return;
    push(idx);
    if(l >= ql && r <= qr){
        seg[idx].val += k;
        seg[idx].tag += k;
        return;
    }
    update(l,mid,ql,qr,k,idx*2);
    update(mid+1,r,ql,qr,k,idx*2+1);
    pull(idx);
}
int query(int l,int r,int ql,int qr,int idx){
    int mid = (l+r)/2;
    if(r < ql || l > qr)return -1;
    push(idx);
    if(l >= ql && r <= qr)return seg[idx].val;
    return max(query(l,mid,ql,qr,idx*2),query(mid+1,r,ql,qr,idx*2+1));
}
int main(){
    strawberry;
    cin >> m;
    for(int i = 0 ; i < m; i++){
        cin >> x1[i] >> Y1[i] >> x2[i] >> y2[i] >> val[i];
        x2[i]++;
        vx.push_back(x1[i]);vx.push_back(x2[i]);
        vy.push_back(Y1[i]);vy.push_back(y2[i]);
    }
    sort(vx.begin(),vx.end());
    vx.resize(unique(vx.begin(),vx.end())-vx.begin());
    sort(vy.begin(),vy.end());
    vy.resize(unique(vy.begin(),vy.end())-vy.begin());
    n = vy.size()-1;
    for(int i = 0 ; i < m ; i++){
        x1[i] = lower_bound(vx.begin(),vx.end(),x1[i])-vx.begin();
        x2[i] = lower_bound(vx.begin(),vx.end(),x2[i])-vx.begin();
        Y1[i] = lower_bound(vy.begin(),vy.end(),Y1[i])-vy.begin();
        y2[i] = lower_bound(vy.begin(),vy.end(),y2[i])-vy.begin();
        side[x1[i]].push_back(i);
        side[x2[i]].push_back(i);
        update(0,n,Y1[i],y2[i],val[i],1);
    }
    int ans = -1,tmp = 0;
    for(int i = 0 ; i < vx.size() ; i++){
        for(int j : side[i]){
            if(bt[j]){
                update(0,n,Y1[j],y2[j],val[j],1);
                bt[j] = 0;
                tmp -= val[j];
            }
            else{
                update(0,n,Y1[j],y2[j],-val[j],1);
                bt[j] = 1;
                tmp += val[j];
            }
        }
        ans = max(ans,tmp + seg[1].val);
    }
    cout << ans << endl;
    return 0;
}