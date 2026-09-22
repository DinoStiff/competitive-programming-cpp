#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define minji ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const ll INF = 1e18;
const int N = 2e5+7;

int main(){
    minji;
    int g[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>g[i][j];
        }
    }
    int x;
    cin>>x;
    if(x==1){
        for(int i=0;i<4;i++){
            int cnt = 0;
            while(1){
                int j=cnt, k, a, b;
                while(j<4&&g[j][i]==0){
                    j++;
                }
                if(j<4){
                    a=g[j][i];
                    k=j+1;
                    while(k<4&&g[k][i]==0){
                        k++;
                    }
                    if(k<4){
                        b = g[j][i];
                        if(a==b){
                            g[j][i]=0;
                            g[k][i]=0;
                            g[cnt][i]=a+b;
                            cnt++;
                        }
                        else{
                            g[j][i]=0;
                            g[k][i]=0;
                            g[cnt][i]=a;
                            g[cnt+1][i]=b;
                            cnt += 2;
                        }
                    }
                    else{
                        g[j][i]=0;
                        g[cnt][i]=a;
                        cnt++;
                    }
                }
                else
                    break;
                
            }
        }
    }
    else if(x==2){
        for(int i=0;i<4;i++){
            int cnt = 3;
            while(1){
                int j=cnt, k, a, b;
                while(j>=0&&g[j][i]==0){
                    j--;
                }
                if(j>=0){
                    a=g[j][i];
                    k=j-1;
                    while(k>=0&&g[k][i]==0){
                        k--;
                    }
                    if(k>=0){
                        b = g[k][i];
                        if(a==b){
                            g[j][i]=0;
                            g[k][i]=0;
                            g[cnt][i]=a+b;
                            cnt--;
                        }
                        else{
                            g[j][i]=0;
                            g[k][i]=0;
                            g[cnt][i]=a;
                            g[cnt-1][i]=b;
                            cnt -= 2;
                        }
                    }
                    else{
                        g[j][i]=0;
                        g[cnt][i]=a;
                        cnt--;
                    }
                }
                else
                    break;
            }
        }
    }
    else if(x==3){
        for(int i=0;i<4;i++){
            int cnt = 0;
            while(1){
                int j=cnt, k, a=0, b=0;
                while(j<4&&g[i][j]==0){
                    j++;
                }
                if(j<4){
                    a=g[i][j];
                    k=j+1;
                    while(k<4&&g[i][k]==0){
                        k++;
                    }
                    if(k<4){
                        b = g[i][k];
                        if(a==b){
                            g[i][j]=0;
                            g[i][k]=0;
                            g[i][cnt]=a+b;
                            cnt++;
                        }
                        else{
                            g[i][j]=0;
                            g[i][k]=0;
                            g[i][cnt]=a;
                            g[i][cnt+1]=b;
                            cnt += 2;
                        }
                    }
                    else{
                        g[i][j]=0;
                        g[i][cnt]=a;
                        cnt++;
                    }
                }
                else
                    break;
            }
        }
    }
    else {
        for(int i=0;i<4;i++){
            int cnt = 0;
            while(1){
                int j=cnt, k, a=0, b=0;
                while(j>=0&&g[i][j]==0){
                    j--;
                }
                if(j>=0){
                    a=g[i][j];
                    k=j-1;
                    while(k>=0&&g[i][k]==0){
                        k--;
                    }
                    if(k>=0){
                        b = g[i][k];
                        if(a==b){
                            g[i][j]=0;
                            g[i][k]=0;
                            g[i][cnt]=a+b;
                            cnt--;
                        }
                        else{
                            g[i][j]=0;
                            g[i][k]=0;
                            g[i][cnt]=a;
                            g[i][cnt-1]=b;
                            cnt -= 2;
                        }
                    }
                    else{
                        g[i][j]=0;
                        g[i][cnt]=a;
                        cnt--;
                    }
                }
                else
                    break;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<g[i][j]<<' ';
        }
        cout<<'\n';
    }
}