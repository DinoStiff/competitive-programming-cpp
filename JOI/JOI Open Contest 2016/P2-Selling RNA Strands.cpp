#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define shadow ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

/*
A-->0
G-->1
C-->2
U-->3
*/



int n, m, bit[N];
vector<int> permut[2], ord[2], pp;

void add(int x){
    for(int i=x;i<=n;i+=i&-1){
        bit[i]++;
    }
}

int query(int l, int r){
    int ans = 0;
    for(int i=r;i>=1;i-=i&-1){
        ans+=bit[i];
    }
    for(int i=l;i>=1;i-=i&-1){
        ans-=bit[i];
    }
}

int trans(char c){
    if(c=='A')
        return 0;
    if(c=='G')
        return 1;
    if(c=='C')
        return 2;
    if(c=='U')
        return 3;
}

struct Trie{
    struct node{
        vector<int> pos;
        ll nxt[4]={-1, -1, -1, -1};
        int l = -1, r = -1;
        // node(int k){

        // }
    }org;


    vector<node> vec;
    Trie(){
        vec.push_back(org);
    }
    
    int len=1;

    void add_str(int cur, int k, int id, string &s){
        if(vec[cur].nxt[trans(s[k])]==-1){
            vec[cur].nxt[trans(s[k])]=len;
            len++;
            vec.push_back(org);
        }
        cur=vec[cur].nxt[trans(s[k])];
        if(k==s.size()-1){
            vec[cur].pos.push_back(id);
            return;
        }
        add_str(cur, k+1, id, s);
    }

    pii init_order(int k, int idx){
        for(auto i:vec[idx].pos){
            permut[k].push_back(i);
            ord[k][i] = permut[k].size()-1;
        }
        int lt=-1;
        if(vec[idx].pos.size()){
            vec[idx].l=vec[idx].pos[0];
            vec[idx].r=vec[idx].pos[vec[idx].pos.size()-1];
            lt=vec[idx].pos[0];
        }
        
        for(int i=0;i<4;i++){
            if(vec[idx].nxt[i]!=-1){
                pii a = init_order(k, vec[idx].nxt[i]);
                vec[idx].r = a.second;
                if(lt==-1){
                    lt=a.first;
                }
            }
        }
        vec[idx].l=lt;
        return {vec[idx].l, vec[idx].r};
    }

    pii find_range(int cur, int k, string &s){
        //cout<<cur<<' '<<k<<' '<<s<<endl;
        if(k==s.size()){
            return {vec[cur].l, vec[cur].r};
        }
        if(vec[cur].nxt[trans(s[k])]==-1){
            return {-1, -1};
        }
        cur = vec[cur].nxt[trans(s[k])];
        
        return find_range(cur, k+1, s);
    }

    void print(int idx){
        cout<<idx<<":\n";
        for(auto i:vec[idx].pos){
            cout<<i<<' ';
        }
        cout<<'\n';
        for(int i=0;i<4;i++){
            cout<<vec[idx].nxt[i]<<' ';
        }
        cout<<'\n';
        cout<<vec[idx].l<<' '<<vec[idx].r<<'\n';
        cout<<"\n";
        for(int i=0;i<4;i++){
            if(vec[idx].nxt[i]!=-1)
                print(vec[idx].nxt[i]);
        }
    }

}trie[2];

struct Query {
    pii r1, r2;
    int idx;
    Query(pii a, pii b, int x){
        r1=a;
        r2=b;
        idx=x;
    }
    ll ans=0;
};

bool cmp1 (Query a, Query b){
    if(a.r1.first==b.r1.first) 
        return a.r1.second<b.r1.second;
    return a.r1.first<b.r1.first;
}

int main(){
    shadow;
    cin>>n>>m;
    ord[0].resize(n+1);
    ord[1].resize(n+1);
    pp.resize(n+1);
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        trie[0].add_str(0, 0, i+1, s);
        reverse(s.begin(), s.end());
        trie[1].add_str(0, 0, i+1, s);
    }
    
    trie[0].init_order(0, 0);
    trie[1].init_order(1, 0);
    //trie[0].print(0);
    string p, q;
    pii a = {-1, -1};

    for(int i=1;i<=n;i++){
        pp[ord[0][i]]=ord[1][i];
        //cout<<ord[0][i]<<' '<<pp[ord[0][i]]<<'\n';
    }
    
    vector<Query> rg;

    for(int i=0;i<m;i++){
        cin>>p>>q;
        reverse(q.begin(), q.end());
        Query tmp(trie[0].find_range(0, 0, p), trie[1].find_range(0, 0, q), i);
        rg.push_back(tmp);
    }

    sort(rg.begin(), rg.end(), cmp1);

    for(auto &i:rg){
        
    }

    if(rg[0]== a||rg[1]==a)
            cout<<0<<'\n';
        else{
            
            for(int i = 0;i<2;i++){
                //cout<<rg[i].first<<' '<<rg[i].second<<'\n';
                for(int j=ord[i][rg[i].first];j<=ord[i][rg[i].second];j++){
                    mp[permut[i][j]]++;
                }
            }
            int ans=0;
            for(auto i:mp){
                if(i==2)
                    ans++;
            }
            cout<<ans<<'\n';
        }
}