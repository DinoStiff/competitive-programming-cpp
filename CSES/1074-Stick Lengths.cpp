#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;
int n, k;
long long ans, cnt;
vector<int> v;

int main(){
    star;
    cin >> n;
	for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
	sort(all(v));
	k = v[n / 2];
	for (int &i : v) {
		ans += abs(k - i);
	}
	cout << ans << '\n';
} 