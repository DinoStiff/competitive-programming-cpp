#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <pii> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i].second >> a[i].first;
    }
    
    sort(a.begin(), a.end());
    int tmp = 0;
    long long ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i].second >= tmp){
           tmp = a[i].first;
           ans++;
        }
    }
    cout << ans << '\n';
}