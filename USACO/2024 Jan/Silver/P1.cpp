#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e5+7;

int seg[N*4], a[N];

int init(int l, int r, int idx){
    if(l==r)
        return seg[idx] = a[l];
    int m = (l+r)/2;
    return seg[idx] = max(init(l, m, idx*2), init(m+1, r, idx*2+1));
}

void modify(int k, int l, int r, int idx){
    //cout << "Modify " << k << " " << l << " " << r << " " << idx << " " << seg[idx].L << " " << seg[idx].R << '\n';
    if(k<l||k>r)
        return;
    if(l == r){
        seg[idx] = a[l];
        return;
    }
    seg[idx] = max(seg[idx], a[k]);
    int m = (l+r)/2;
    if(k<=m){
        modify(k, l, m, idx*2);
    }
    else{
        modify(k, m+1, r, idx*2+1);
    }
}

int query(int ql, int qr, int l, int r, int idx){
    if(qr<ql)
        return 0;
    if(r<ql||qr<l)
        return 0;
    if(ql<=l&&r<=qr)
        return seg[idx];
    int m = (l+r)/2;
    return max(query(ql, qr, l, m, idx*2), query(ql, qr, m+1, r, idx*2+1));
}

int main(){
    star;
    int t;
    cin>>t;
    while(t--){
        int n, q, c;
        bool ok=1;
        cin>>n>>q>>c;
        vector<pii> v(q);
        set<int> z;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0){
                z.insert(i);
            }
        }
        for(int i=0;i<q;i++){
            cin>>v[i].second>>v[i].first;
        }
        sort(all(v));
        init(1, n, 1);
        for(auto i:v){
            auto f = z.upper_bound(i.second);
            int tmp = query(1, i.second, 1, n, 1);
            int first = query(i.second+1, i.first-1, 1, n, 1);
            if(f!=z.begin()){
                if(first>tmp){
                    for(auto j=z.begin();j!=f;j++){
                        a[*j]=first;
                    }
                }
                else{
                    for(auto j=z.begin();j!=f;j++){
                        a[*j]=1;
                    }
                }
            }
            a[i.first]=tmp+1;
            modify(i.first, 1, n ,1);
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            cout<<'\n';
        }
        if(ok){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            cout<<'\n';
        }
        else
            cout<<"-1\n";
    }
}