#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define nice ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    nice;
    int n;
	priority_queue<long long, vector<long long>, greater<long long> >pq;
	long long tmp, ans = 0;
	cin >> n >> tmp;
	for (int i = 0; i < n; i++) {
        ll a;
		cin >> a;
		tmp -= a;
		pq.push(a);
	}
	if (tmp > 0) {
		pq.push(tmp);
		n++;
	}
    ll a, b;
	for (int i = 0; i < (n - 1); i++) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans << endl;
	return 0;
}