#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define shadow ios::sync_with_stdio(false), cin.tie(0)
#define int ll
using namespace std;

const ll INF = LLONG_MAX;
const int N = 2e5+7;
const int md = 1e9+7;

int trie[1000005][26];
bool stop[1000005];
int dp[5005];
int cnt = 0;

void insert(string s) {
    int node = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!trie[node][s[i]-'a']) trie[node][s[i]-'a'] = ++cnt;
        node = trie[node][s[i]-'a'];
    }
    stop[node] = 1;
}
string s;
int search(int x) {
    int node = 0, ans = 0;
    for (int i = x; i < s.size(); i++) {
        if (!trie[node][s[i]-'a']) return ans;
        node = trie[node][s[i] - 'a'];
        if (stop[node]) {
            (ans += dp[i+1])%=md;
        }
    }
    return ans;
}

signed main(){
    shadow;
    cin>>s;
    int k; cin>>k;
    while(k--) {
        string x;
        cin>>x;
        insert(x);
    }
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i>=0; i--) {        
        dp[i] = search(i);
    }
    cout<<dp[0]<<'\n';
}