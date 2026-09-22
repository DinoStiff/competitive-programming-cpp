#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[25];
int solve(int cur,int tol,int i){
    if (i==0)
        return abs((tol-cur) - cur);
    return min(solve(cur+arr[i],tol,i-1),solve(cur,tol,i-1));

}
signed main(){
    int n;
    cin>>n;
    int tol=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tol+=arr[i];
    }

    cout<<solve(0,tol,n-1)<<endl;
    return 0;
    
}