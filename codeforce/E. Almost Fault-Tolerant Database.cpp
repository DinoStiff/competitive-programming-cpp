#include<bits/stdc++.h>
#define nice ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n, m;
vector<int>a[250005];
#define pii pair<int, int>
#define fi first
#define se second
pii check(vector<int>s){
    int maxn=0, maxid=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++)if(a[i][j-1]!=s[j-1])cnt++;
        if(cnt>=maxn)maxn=cnt, maxid=i;
    }
    return {maxn, maxid};
}
void print(vector<int>s){
    cout<<"Yes\n";
    for(int i=1;i<=m;i++)cout<<s[i-1]<<" ";
    return;
}
signed main(){
    nice;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    pii tmp=check(a[1]);
    if(tmp.fi<=2){
        print(a[1]);
        return 0;
    }
    if(tmp.fi>4){
        cout<<"No\n";
        return 0;
    }
    if(tmp.fi==4){
        int pos[5], sum=0;
        for(int i=1;i<=m;i++)if(a[1][i-1]!=a[tmp.se][i-1])pos[++sum]=i;
        vector<int>now;
        for(int i=1;i<=sum;i++){
            for(int j=i+1;j<=sum;j++){
                now=a[1];
                now[pos[i]-1]=a[tmp.se][pos[i]-1];
                now[pos[j]-1]=a[tmp.se][pos[j]-1];
                if(check(now).fi<=2){
                    print(now);
                    return 0;
                }
            }
        }
        cout<<"No\n";
        return 0;
    }
    int pos[4], sum=0;
    for(int i=1;i<=m;i++)if(a[1][i-1]!=a[tmp.se][i-1])pos[++sum]=i;
    vector<int>now;
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=sum;j++){
            if(i==j)continue;
            for(int k=1;k<=sum;++k){
                if(i==k||j==k)continue;
                now=a[1];
                now[pos[j]-1]=a[tmp.se][pos[j]-1];
                pii o=check(now);
                if(o.fi<=2){
                    print(now);
                    return 0;
                }   
                now[pos[k]-1]=a[o.se][pos[k]-1];
                if(check(now).fi<=2){
                    print(now);
                    return 0;
                }
            }
        }
    }
    cout<<"No\n";
    return 0;
}