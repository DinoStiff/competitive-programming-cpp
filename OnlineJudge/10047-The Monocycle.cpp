#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define good_luck ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

const int INF=1e9+7;
const int N=30;
string grid[N];
int vis[N][N][4][5];
int dp[N][N][4][5];
int sx, sy, ex, ey;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
int m, n, ans;

struct node{
	int x, y, dir, col;
	node(int x,int y,int dir,int col): x(x), y(y), dir(dir), col(col){}
};

queue<node>q;

void add(int x,int y,int dir,int col,int v){
	if(x<0||y<0||x>=m||y>=n)
        return;
	if(grid[x][y]=='#' || vis[x][y][dir][col]==1)
        return;
	vis[x][y][dir][col]=1;
	dp[x][y][dir][col]=v;
	q.push(node(x, y, dir, col));
	if(x==ex && y==ey && !col)
        ans = min(ans, v);
}

void bfs(){
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
	q.push(node(sx, sy, 0, 0));
	vis[sx][sy][0][0]=1;
	while(!q.empty()){
		node temp=q.front();
        q.pop();
		int v=dp[temp.x][temp.y][temp.dir][temp.col]+1;
		
		add(temp.x, temp.y, (temp.dir+1)%4, temp.col,v);
		add(temp.x,temp.y, (temp.dir+3)%4, temp.col, v);
		add(temp.x+dx[temp.dir], temp.y+dy[temp.dir], temp.dir, (temp.col+1)%5, v);
	}
}

int main(){
    good_luck;
	int cnt=0;
	while(cin>>m>>n && m){
		for(int i=0;i<m;i++){
			cin>>grid[i];
			for(int j=0;j<n;j++){
				if(grid[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
				else if(grid[i][j]=='T'){
                    ex=i;
                    ey=j;
                }
			}
		}
		ans=INF;
		if(cnt)
            cout<<'\n';
        cnt++;
		cout<<"Case #"<<cnt<<'\n';
		bfs();
		if(ans==INF)
            cout << "destination not reachable\n";
		else cout << "minimum time = " << ans <<" sec\n";

	}
	return 0;
}