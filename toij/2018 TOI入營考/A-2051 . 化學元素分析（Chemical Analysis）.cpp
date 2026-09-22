#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 260;
string s;
int cof[N], n;
stack<int> st;
queue<string> q;
map<string, int> m;
int main(){
    star;
    cin>>s;
    n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(')
            st.push(i+1);
        else if(s[i]==')'){
            int l = st.top(), r = i;
            st.pop();
            i++;
            int tmp=0;
            for(i;i<n;i++){
                if('0'<=s[i]&&s[i]<='9'){
                    tmp*=10;
                    tmp+=s[i]-'0';
                }
                else{
                    i--;
                    break;
                }
            }
            if(tmp==0)
                tmp=1;
            for(int j=l;j<=r;j++){
                //cout<<j<<' '<<cof[j]<<' ';
                cof[j]*=tmp;
                //cout<<cof[j]<<'\n';
            }
        }
        else if('0'<=s[i]&&s[i]<='9'){
            int k=i;
            int tmp=0;
            for(i;i<n;i++){
                if('0'<=s[i]&&s[i]<='9'){
                    tmp*=10;
                    tmp+=s[i]-'0';
                }
                else{
                    i--;
                    break;
                }
            }
            cof[k] *= tmp;
        }
        else{
            if(i+1<n&&'a'<=s[i+1]&&s[i+1]<='z'){
                q.push(s.substr(i, 2));
                i++;
            }
            else
                q.push(s.substr(i, 1));
            cof[i+1]=1;
        }
    }
    int i = 0;
    while(q.size()){
        int tmp;
        string t = q.front();
        q.pop();
        for(i;i<=n;i++){
            if(cof[i]){
                tmp = cof[i];
                i++;
                break;
            }
        }
        m[t]+=tmp;
    }
    cout<<s<<'\n';
    for(auto i:m){
        cout<<i.first<<':'<<i.second<<'\n';
    }
}