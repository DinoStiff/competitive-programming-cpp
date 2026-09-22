#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define pii pair<int,int>
 
bool cmp(pii a, pii b){
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
 
int main(){
    int n;
    vector <pii>v;
    while (cin >> n){
        int a, b, c, maxi = 0, ans = 0;
        v.clear();
        for (int i = 0; i < n; i++){
            cin >> a >> b >> c;
            v.push_back({a*a + b*b, c});
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; i++){
            ans = max(ans, maxi-v[i].second);
            maxi = max(maxi, v[i].second);
        }
        cout << ans << "\n";
    }
}