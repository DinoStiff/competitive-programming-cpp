#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    while (cin >> n){
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        cout << a[0] << ' ' << a[n-1] << ' ';
        if (n-1 == a[n-1]-a[0]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}