#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int cnt = 0;
    string s;
    cin >> s;
    int arr[30] = {0};
    for (int i = 1; i <= 26; i++)
    {
        arr[s[i - 1] - 'A' + 1] = i;
    }
    for (int i = 2; i <= 26; i++)
    {
        cnt = cnt + abs(arr[i] - arr[i - 1]);
    }
    cout << cnt << '\n';
}