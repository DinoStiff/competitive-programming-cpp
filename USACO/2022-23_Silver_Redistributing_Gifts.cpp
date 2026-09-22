#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define star ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e17;
const int N = 507;

vector<int> v[N], rev[N];
bool vis[N];
vector<int> path;
set<int> s;

void dfs(int node) {
	vis[node] = true;
	for (int i : v[node]) {
		if (!vis[i]) { dfs(i); }
	}
	path.push_back(node);
}

void dfs2(int node) {
	vis[node] = true;
	for (int i : rev[node]) {
		if (!vis[i]) { dfs2(i); }
	}
	s.insert(node);
}

int main(){
    star;
    int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
            int a;
            cin>>a;
            v[i].push_back(a);
        }
		while (v[i].back() != i) {
            v[i].pop_back();
        }
		for (int j : v[i]){
            rev[j].push_back(i);
        }
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]){
            dfs(i);
        }
	}

	reverse(path.begin(), path.end());
    memset(vis, 0, sizeof vis);
	vector<int> ans(n + 1);
	for (int i : path) {
		if (!vis[i]) {
			dfs2(i);
			for (int j : s) {
				for (int k : v[j]) {
					if (s.count(k)) {
						ans[j] = k;
						break;
					}
				}
			}
			s.clear();
		}
	}

	for (int i = 1; i <= n; i++) { cout << ans[i] << endl; }
}