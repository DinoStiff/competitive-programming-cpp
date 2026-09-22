#include <bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;
int n;
 
signed main(){
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        int l = max(x,y)-1,cng = l*l;
        if(!(l % 2)){
            if(y < l+1)
                cout<<cng+y<<endl;
            else
                cout<<(cng+l+1)+(l+1-x)<<endl;
        }
        else{
            if(x < l+1)
                cout<<cng+x<<endl;
            else
                cout<<(cng+l+1)+(l+1-y)<<endl;
        }
    }
}