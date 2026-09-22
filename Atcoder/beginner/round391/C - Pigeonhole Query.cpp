#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 1e6+7;

int n, m;
int arr[N], t[N], ans;

int main(){
    minji;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i]=i;
        t[i]=1;
    }
    while(m--){
        int op, a, b;
        cin>>op;
        if(op==1){
            cin>>a>>b;
            t[arr[a]]--;
            if(t[arr[a]]==1)
            {
            	ans--;
			}
            arr[a]=b;
            t[arr[a]]++;
            if(t[arr[a]]==2)
            {
            	ans++;
			}
        }
        else{
        	cout<<ans<<'\n';
		}
    }
}