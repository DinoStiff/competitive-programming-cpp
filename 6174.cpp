#include <bits/stdc++.h>
using namespace std;


string cal(string a, string b){
    string ans;
    int l = a.size();
    for(int i=l-1;i>=0;i--){
        if(a[i]<b[i]){
            ans+=a[i]-b[i]+10+'0';
            a[i-1]--;
        }
        else{
            ans+=a[i]-b[i]+'0';
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, l;
    cin>>n>>l;
    while(n--){
        string s, a, b;
        cin>>s;
        set<string> st;
        while(s.size()<l){
            s.insert(s.begin(), '0');
        }
        while(!st.count(s)){
            st.insert(s);
            a = b = s;
            sort(a.begin(), a.end());
            sort(b.rbegin(), b.rend());
            s = cal(b, a);
            //cout<<s<<endl;
        }
        cout<<s<<endl;
    }
}
