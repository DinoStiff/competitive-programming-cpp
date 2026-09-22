#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e8;
const int N = 2e5+7;

int a[N];
int seg[N * 4];
bool vis[N];
void update(int x, int k, int s, int t, int idx)
{  
    if (s == t)
    {
        seg[idx] = k;
        return;
    }
    int mid = (s + t) >> 1;
    if (mid >= x)
        update(x, k, s, mid, idx * 2 + 1);
    else
        update(x, k, mid + 1, t, idx * 2 + 2);
    seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int l, int r, int s, int t, int idx)
{
    if(l > r) return -1;
    if (l <= s && t <= r)
        return seg[idx];
    int mid = (s + t) >> 1;
    int sum = INF;
    if (l <= mid)
        sum = min(sum, query(l, r, s, mid, idx * 2 + 1));
    if (r > mid)
        sum = min(sum, query(l, r, mid + 1, t, idx * 2 + 2));
    return sum;
}

int main(){
    minji;
    int n;
    cin >> n;
    int k = 0;
    bool f1 = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], k = max(k, a[i]);
    k += 2;
    vector<int> ans;
    for (int i = 1; i <= n; i++){
        if(a[i] != 1) f1 = 1;
        if(vis[a[i]]) {
            update(a[i], i, 1, k, 0);
            continue;
        }
        int x = query(a[i], a[i], 1, k, 0);
        int y = query(1, a[i] - 1, 1, k, 0);
        if (y > x)
            ans.push_back(a[i]), vis[a[i]] = 1;
        update(a[i], i, 1, k, 0);    
    } 
    for (int i = 1; i <= k; i++){
        if (!vis[i]){
            int x = query(i, i, 1, k, 0);
            int y = query(1, i - 1, 1, k, 0);
            if (y > x)
                ans.push_back(i), vis[i] = 1;
        }
    }
    if(f1) ans.push_back(1);
    sort(all(ans));
    for(int i = 0 ; i < ans.size(); i++)
    {
        if(ans[i] != i + 1)
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << ans.size() + 1 << '\n';
}