#include <iostream>
using namespace std;
  
long long n, a, b, c, p = 1e9+7;
  
long long pw(long long x, long long y, long long z){
    long long ret = 1, now = x;
    while (y){
        if (y&1){
            ret *= now;
            ret %= z;
        }
        y >>= 1;
        now *= now;
        now %= z;
    }
    return ret;
}
  
int main() {
    cin >> n;
    while (n--){
        cin >> a >> b >> c;
        b = pw(b, c, p-1);
        a = pw(a, b, p);
        cout << a << "\n";
    }
}