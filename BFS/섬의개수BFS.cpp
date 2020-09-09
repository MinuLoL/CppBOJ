#include<bits/stdc++.h>
using namespace std;

int w,h,cnt,X,Y;
int maps[50][50];
int visited[50][50];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
vector<int>v;
bool isInMap(int y,int x){
	return ((y>=0&&y<h)&&(x>=0&&x<w));
}

void init()
{
	cnt=0;
	for(int i=0;i<h;++i)
	{
		for(int j=0;j<w;++j)
		{
			maps[i][j]=0;
			visited[i][j]=false;
		}
	}
}
void bfs(int y,int x)
{
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	visited[y][x]=1;
	
	while(!q.empty()){
		y=q.front().first;
		x=q.front().second;
		q.pop();
		for(int i=0;i<8;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInMap(ny,nx)&&!visited[ny][nx]&&maps[ny][nx])
			{
				visited[ny][nx]=1;
				q.push(make_pair(ny,nx));
			}
		}
	}
}
int main()
{
	cin>>w>>h;
	while(w!=0&&h!=0)
	{
		init();
		for(int i=0;i<h;++i)
		{
			for(int j=0;j<w;++j)
			{
				cin>>maps[i][j];
			}
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (maps[i][j] && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);
		cin>>w>>h;				
	}
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
}

