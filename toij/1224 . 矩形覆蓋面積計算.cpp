#include <bits/stdc++.h>
#define strawberry ios::sync_with_stdio(0), cin.tie(0);
#define N 100005
#define M 1000001
#define ll long long
using namespace std;
int n;

struct node {
    int x1;
    int x2;
    int y;
    int val;

} arr[2 * N];

struct Tree {
    int val;
    int tag;

} seg[4 * M];

bool cmp(node a, node b) { return a.y < b.y; }

void modify(int idx, int l, int r, int ql, int qr, int val) {
    if (r <= l || ql >= r || qr <= l)
        return;
    if (ql <= l && qr >= r) {
        seg[idx].tag += val;
        return;
    }
    int mid = (l + r) / 2;
    modify(2 * idx, l, mid, ql, qr, val);
    modify(2 * idx + 1, mid, r, ql, qr, val);

    seg[idx].val = (seg[2 * idx].tag ? mid - l : seg[2 * idx].val) + (seg[2 * idx + 1].tag ? r - mid : seg[2 * idx + 1].val);
}

int main() {
    strawberry;
    memset(arr, 0, sizeof(arr));
    memset(seg, 0, sizeof(seg));

    cin >> n;
    for (int i = 0; i < (n << 1); i += 2) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        arr[i] = {x1, x2, y1, 1};
        arr[i + 1] = {x1, x2, y2, -1};
    }
    stable_sort(arr, arr + (n << 1), cmp);

    int y0 = 0, val = 0;
    ll ans = 0LL;
    for (int i = 0; i < (n << 1); i++) {
        ans += (ll)(arr[i].y - y0) * val;
        modify(1, 0, M, arr[i].x1, arr[i].x2, arr[i].val);
        y0 = arr[i].y;
        val = seg[1].val;
    }
    cout << ans << '\n';
}