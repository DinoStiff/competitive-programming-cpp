#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

stack<char> st;

//(:1 ):2 [:3 ]:4 <:5 >:6

bool lf(char a){
    if(a=='('||a=='['||a=='<')
        return 1;
    return 0;
}

bool match(char a){
    if(st.empty())
        return 0;
    if(st.top()==(a-1)||st.top()==(a-2))
        return 1;
    return 0;
}

int main(){
    minji;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(lf(s[i])){
            st.push(s[i]);
        }
        else{
            if(!match(s[i])){
                cout<<"No\n";
                return 0;
            }
            //if(!st.empty())
                st.pop();
        }
    }
    if(st.empty())
        cout<<"Yes\n";
    else
        cout<<"No\n";
}