#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 2e5+7;

int main(){
    star;
    int n;
	cin >> n;

	vector<int> f(n);
	for (int i=0;i<n;i++) {
        cin>>f[i];
    }

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			double avg = 0;
			for (int k = i; k <= j; k++) {
                avg += f[k];
            }
			avg /= j - i + 1;

			for (int l = i; l <= j; l++) {
				if (f[l] == avg) {
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << endl;
}