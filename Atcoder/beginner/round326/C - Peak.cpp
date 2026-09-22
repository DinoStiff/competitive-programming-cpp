#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int n, m, a[300005], r, ans;

int main(){
    minji;
    cin>>n>>m;
	m -= 1;
	for(int i=1; i <= n; ++i){
		cin>>a[i];
	} 
	sort(a + 1, a + 1 + n);
	for(int i=1; i <= n; ++i) {
		while (a[r + 1] - a[i] <= m && r <= n-1) r++;
		if(ans < r - i + 1){
			ans = r - i + 1;
		}
	}
	cout << ans << '\n';
}