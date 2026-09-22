#include <iostream>
#include <vector>
using namespace std;
  
int n, x, dp[1000005];
  
int main() {
    cin >> n;
    for (int i = 2; i < 1000005; i++){
        if (!dp[i]){
            for (int j = i; j < 1000005; j += i){
                dp[j] = i;
            }
        }
    }
    while (n--){
        cin >> x;
        vector <pair<int, int> > v;
        int ans = 1;
        while (dp[x]){
            if (!v.empty() && dp[x] == v.back().first) v.back().second++;
            else v.push_back({dp[x], 2});
            x /= dp[x];
        }
        for (auto i:v){
            ans *= i.second;
        }
        cout << ans << "\n";
    }
}