#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int N = 2e5+2;

ll arr[N], arr2[N];

vector<int> vec[N];
int n, m;

void build(vector<int> &fail, string q){
    int idx1=0, idx2=-1;
    fail.push_back(-1);
    while(idx1<q.size()){
    if(idx2==-1||q[idx1]==q[idx2]){
        idx1++, idx2++;
        fail.push_back(idx2);
    }
    else
        idx2=fail[idx2];
    }
}

void kmp(string s, string q, int v, int l){
    if(vec[l].size()!=0){
        for(auto i:vec[l]){
            arr[i-l]+=v;
            arr2[i]+=v;
        }
        return;
    }
    else{
        vector<int> fail;
        build(fail, q);
        int idx1=0, idx2=0;
        while(idx1<s.size()){
        if(idx2==-1||s[idx1]==q[idx2]){
            idx1++, idx2++;
            if(idx2==q.size()){
                idx2=fail[idx2];
                arr[idx1-l]+=v;
                arr2[idx1]+=v;
                //cout<<idx1-l<<' ';
                if(l<=(ll)n/8.845)
                    vec[l].push_back(idx1);
            }
        }
        else
            idx2=fail[idx2];
        }
    }
}

int main(){
    minji;
    cin>>n>>m;
    string s;
    cin>>s;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x, v;
            cin>>x>>v;
            string nd = s.substr(0, x);
            kmp(s, nd, v, x);
            //cout<<'\n';
        }
        else{
            int x;
            cin>>x;
            cout<<arr[x]<<' '<<arr2[x]<<'\n';
        }
    }
}