#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e5+7;

ll ans=-INF;

struct Node{
    ll score;
    ll fir=-INF, sec=-INF;
    ll best=-INF;
    vector<int> path;

    void cmp(ll x){
        if(x>=fir){
            sec=fir;
            fir=x;
        }
        else{
            sec=max(x, sec);
        }
    }

    void find_best(){
        //cout<<ans<<' '<<score<<' '<<fir<<' '<<sec<<'\n';
        best=max(score, score+fir);
        ans=max({ans, best, best+sec});
    }

};

vector<Node> graph(N);
vector<int> cycle;
int k;

ll find_score(int x, int f, int ff){
    for(int i:graph[x].path){
        if(i!=f&&i!=ff){
            graph[x].cmp(find_score(i, x, ff));
        }
    }
    //cout<<x<<' ';
    graph[x].find_best();
    return graph[x].best;
}

bool used[N], fd=0;
vector<ll> st;

void find_cycle(int x, int f){
    if(fd)
        return;
    st.push_back(x);
    used[x]=1;
    for(int i:graph[x].path){
        if(i!=f){
            if(used[i]){
                fd=1;
                return;
            }
            find_cycle(i, x);
        }
    }
    /*cout<<x<<'\n';
    for(auto i:st){
        cout<<i<<' ';
    }
    cout<<'\n';*/
    if(!fd)
        st.pop_back();
    return;
}

int main(){
    star;
    int n, m;
    cin>>n>>m;
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].path.push_back(b);
        graph[b].path.push_back(a);
    }
    for(int i=1;i<=n;i++){
        cin>>graph[i].score;
    }
    if(m==n-1){
        find_score(1, 0, 0);
        cout<<ans<<'\n';
    }
    else{
        find_cycle(1, 0);
        int tmp=st.back();
        //cout<<tmp<<'\n';
        st.clear();
        fd=0;
        memset(used, 0, sizeof used);
        find_cycle(tmp, 0);
        while(st.size()){
            cycle.push_back(st.back());
            st.pop_back();
        }
        k=cycle.size();
        /*
        for(int i=0;i<k;i++){
            cout<<cycle[i]<<' ';
        }
        cout<<'\n';
        */
        for(int i=0;i<k;i++){
            find_score(cycle[i], cycle[(i-1+k)%k], cycle[(i+1+k)%k]);
            //cout<<cycle[(i-1+k)%k]<<' '<<cycle[(i+1+k)%k]<<'\n';
        }
        
        ll pre[k+2], m1[k+2], m2[k+2];
        pre[0]=0;
        for(int i=1;i<=k;i++){
            pre[i]=pre[i-1]+graph[cycle[i-1]].score;
            //cout<<pre[i]<<' ';
        }
        //cout<<'\n';
        m1[k+1]=-INF;
        for(int i=k;i>=2;i--){
            m1[i]=max(m1[i+1], pre[i]+graph[cycle[i-1]].best-graph[cycle[i-1]].score);
            
        }
        m2[k]=-INF;
        for(int i=k-1;i>=1;i--){
            m2[i]=max(m2[i+1], -pre[i]+pre[k]+graph[cycle[i]].best-graph[cycle[i]].score);
            //cout<<cycle[i-1]<<' '<<m2[i]<<' '<<graph[cycle[i-1]].best<<' '<<graph[cycle[i-1]].score<<'\n';
        }
        for(int i=1;i<k;i++){
            ans=max(ans, m1[i+1]+graph[cycle[i-1]].best-graph[cycle[i-1]].score-pre[i-1]);
            ans=max(ans, m2[i]+graph[cycle[i-1]].best-graph[cycle[i-1]].score+pre[i]);
        }
        
        cout<<ans<<'\n';
    }
}