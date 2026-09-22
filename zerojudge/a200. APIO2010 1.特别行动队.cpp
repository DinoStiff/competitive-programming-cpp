#include <iostream>
using namespace std;
const int N = 1000005;
#define ll long long
ll f[N], s[N];
int q[N], a, b, c;
ll k(int i){
    return 2 * a * s[i];
}
ll x(int i){
    return s[i];
}
ll y(int i){
    return f[i] + a * s[i] * s[i] - b * s[i];
}
double get(int i,int j){
    return (double)(y(i) - y(j)) / (x(i) - x(j));
}
int main(){
    int n;
    cin>>n>>a>>b>>c;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        s[i] += s[i - 1];
    }
    int tmp = 0, cnt = 0;
    for (int i=1;i<=n;i++){
        while (tmp < cnt && get(q[tmp], q[tmp + 1]) > k(i))
            tmp ++;
        f[i] = -k(i) * x(q[tmp]) + y(q[tmp]) + a * s[i] * s[i] + b * s[i] + c;
        while (tmp < cnt && get(q[cnt - 1], q[cnt]) <= get(q[cnt], i))
            cnt --;
        q[++cnt] = i;
    }
    cout<<f[n]<<'\n';
    return 0;
}