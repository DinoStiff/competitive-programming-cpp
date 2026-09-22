#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define shadow ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

struct Trie {
	Trie *chl[2] = {};
	int cnt = 0;
};

void add(Trie *rt, int x) {
	Trie *cur = rt;
	for (int i = 30; i >= 0; i--) {
		bool ok = x & (1 << i);
		if (cur->chl[ok] == NULL) {
			cur->chl[ok] = new Trie;
		}
		cur->chl[ok]->cnt++;
		cur = cur->chl[ok];
	}
}

void remove(Trie *rt, int x) {
	Trie *cur = rt;
	for (int i = 30; i >= 0; i--) {
		bool ok = x & (1 << i);
		cur->chl[ok]->cnt--;
		cur = cur->chl[ok];
	}
}

int query(Trie *rt, int x) {
	Trie *cur = rt;
	int res = 0;
	for (int i = 30; i >= 0; i--) {
		bool ok = x & (1 << i);
		if (cur->chl[ok] != NULL && cur->chl[ok]->cnt > 0) {
			cur = cur->chl[ok];
		} else {
			cur = cur->chl[!ok];
			res += 1 << i;
		}
	}
	return res;
}

int main(){
    shadow;
    Trie tr;
	int q;
	cin >> q;
	set<int> s;
	for (int i = 0; i < q; i++) {
		int t, x;
		cin >> t >> x;
		if (t == 0) {
			if (!s.count(x)) {
				s.insert(x);
				add(&tr, x);
			}
		} else if (t == 1) {
			if (s.count(x)) {
				s.erase(x);
				remove(&tr, x);
			}
		} else {
			cout << query(&tr, x) << "\n";
		}
	}
}