#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int T;
    cin>>T;
    while(T--){
        int n, p;
        cin>>n>>p;
        stack<char> a, b, c;
        char ea, eb;
        string sa, sb;
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            if(a.size()){
                if(a.top()!=x)
                    a.push(x);
            }
            else{
                a.push(x);
                ea=x;
            }
            sa+=x;
        }
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            if(b.size()){
                if(b.top()!=x)
                    b.push(x);
            }
            else{
                b.push(x);
                eb=x;
            }
            sb+=x;
        }
        int ans = a.size()+b.size();
        //cout<<ans<<' '<<a.top()<<' '<<b.top()<<' '<<ea<<' '<<eb<<'\n';
        if(a.size()==1&&b.top()==ea&&b.size()==2)
            cout<<"1\n";
        else if(b.size()==1&&a.top()==eb&&a.size()==2)
            cout<<"1\n";
        else if(a.size()==1&&b.size()==1){
            cout<<0<<'\n';
            continue;
        }
        else if(ea==eb)
            cout<<ans<<'\n';
        else
            cout<<ans-1<<'\n';
        if(p>1){
            if(a.size()==1&&b.top()==ea&&b.size()==2)
                cout<<"2 1\n";
            else if(b.size()==1&&a.top()==eb&&a.size()==2)
                cout<<"1 2\n";
            else if(a.size()>=b.size()){
                while(b.size()>1){
                    if(a.top()!=b.top()){
                        cout<<"2 3\n";
                        if(!c.size())
                            c.push(b.top());
                        b.pop();
                    }
                    else{
                        cout<<"2 1\n";
                        b.pop();
                    }
                }
                while(a.size()>1){
                    if(a.top()!=b.top()){
                        cout<<"1 3\n";
                        a.pop();
                    }
                    else{
                        cout<<"1 2\n";
                        a.pop();
                    }
                }
                if(ea==eb)
                    cout<<"1 2\n3 1\n";
                else
                    cout<<"3 1\n";
            }
            else{
                swap(a, b);
                while(b.size()>1){
                    if(a.top()!=b.top()){
                        cout<<"1 3\n";
                        if(!c.size())
                            c.push(b.top());
                        b.pop();
                    }
                    else{
                        cout<<"1 2\n";
                        b.pop();
                    }
                }
                while(a.size()>1){
                    if(a.top()!=b.top()){
                        cout<<"2 3\n";
                        a.pop();
                    }
                    else{
                        cout<<"2 1\n";
                        a.pop();
                    }
                }
                if(ea==eb)
                    cout<<"2 1\n3 2\n";
                else
                    cout<<"3 2\n";
            }
            
        }
    }
}