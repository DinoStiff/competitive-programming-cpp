#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

vector<pair<int,int>> vec;

signed main(){
    minji;
    int n,m,k;
    cin>>n>>m>>k;

    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(make_pair(x,i));
        sum+=x;
    }
    sort(vec.begin(),vec.end());

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++){
        a[i]=vec[n-1-i];
    }

    vector<int> v(n,0);
    vector<int> tmp;

    if (m+1<=n){

        int cnt=0;
        for (int i=m-2;i>=0;i--){
            cnt+=(m-i)*(a[i].first-a[i+1].first);
            tmp.push_back(cnt);
        }


        for (int i=0;i<n;i++){
            int num=0;
            if(i>=m){
                num=a[m-1].first-a[i].first;
            }

            if (num>k-sum) {
                v[a[i].second]=-1;
                continue;
            }

            int num2=a[m-1].first-a[m].first;
            if(i>=m){
                num2=0;
            }

            auto it = upper_bound(tmp.begin(), tmp.end(), k-sum-num-num2);
            int x = distance(tmp.begin(), it)+2;
            int y = k-sum-num-num2;

            int z = a[m-x+1].first;
            if (x>2)
            {
                y-=tmp[x-3];
            }
            z+=(y+1)/x;
            
            v[a[i].second]=max(0ll, z-a[i].first);
        }


    

    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";

    
 
    return 0;
}