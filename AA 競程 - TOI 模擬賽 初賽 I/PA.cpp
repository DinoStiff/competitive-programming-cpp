#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 1e6+7;

int main(){
    star;
    string a, b;
    cin>>a>>b;
    multiset<char> ms;
    string need;
    for(char i:b){
        ms.insert(i);
    }
    for(int i=0;i<a.size();i++){
        auto tmp = ms.lower_bound(a[i]);
        if(tmp == ms.end()){
            ms.insert(need[i]);
            tmp = ms.upper_bound(need[i]);
            continue;
        }
        if(*tmp == '0'&&i==a.size()-1){
            tmp = ms.upper_bound('0');
        }
        if(tmp == ms.end()){
            need+=*prev(tmp);
        }
        need+=*tmp;
        ms.erase(tmp);
    }
    for(auto i:ms){
        need+=i;
    }
    int ans[N], num[N];
    int l = need.size();
    for (int i = l-1, j = 0; i >= 0; i--, j++) 
        ans[j] = need[i] - '0';
    for (int i = a.size()-1, j = 0; i >= 0; i--, j++)
        num[j] = a[i] - '0';
    for (int i = 0; i < l; i++){
        ans[i] = ans[i] - num[i];
        if (ans[i] < 0){
            ans[i] += 10;
            ans[i+1]--;
        }
    }
    while(l&&ans[l-1]==0){
        l--;
    }
    if(l==0){
        cout<<0;
    }
    for(int i=l-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<'\n';
}