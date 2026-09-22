#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF = 1e9;
const int N = 2e5+7;

vector<int> a(6), b;
vector<pii> note;

int main(){
    minji;
    for(int i=0;i<6;i++){
        cin>>a[i];
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
        for(int j=0;j<6;j++){
            note.push_back({b[i]-a[j], i});
        }
    }
    sort(all(note));
    vector<int> v(n, 0);
    int cnt=0, ans=INF, l=0, r=0, m=note.size();
    while(r<m){
        while(r<m && cnt<n){
            if(!v[note[r].second])
                cnt++;
            v[note[r].second]++;
            r++;
        }
        while(l<r && cnt==n){
            ans = min(ans, note[r-1].first-note[l].first);
            v[note[l].second]--;
            if(!v[note[l].second])
                cnt--;
            l++;
        }
    }
    cout<<ans<<'\n';
    ll aaa=1e18+7;
    cout<<aaa;
}