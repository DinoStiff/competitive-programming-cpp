#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n, q, t[N];
char h[N];
int ans;
int main(){
	cin >> n >> q;
	int l = 0, r = 1;
	for(int i = 1; i <= q; i++){
		cin >> h[i] >> t[i];
		t[i]--;
        int cnt=0, f=0;
		if(h[i]=='L'){
			while(l != t[i]){
				l = (l+1) % n;
				if(l==r)
                    f=1;
				cnt++;
			}

		}
		else{
			while(r!=t[i]){
				r = (r+1) % n;
				if(l==r)
                    f=1;
				cnt++;
			}
		}
        if(f)
            cnt = n-cnt;
		ans += cnt;
	}
	cout << ans <<'\n';
	return 0;
} 