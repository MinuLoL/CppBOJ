#include<bits/stdc++.h>
using namespace std;

int testcase,chesslen;
int dy[]={-2,-1,1,2,2,1,-1,-2};
int dx[]={1,2,2,1,-1,-2,-2,-1};

int maps[301][301];
int visited[301][301];
vector<int> v;

void init()
{
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
}
bool isInMap(int y,int x)
{
	return ((y>=0&&y<chesslen)&&(x>=0&&x<chesslen));
}

void bfs(int y,int x)
{
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	visited[y][x]=1;
	
	while(!q.empty())
	{
		y=q.front().first;
		x=q.front().second;
		q.pop();
		for(int i=0;i<8;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInMap(ny,nx)&&!visited[ny][nx]&&!maps[ny][nx])
			{
				visited[ny][nx]=visited[y][x]+1;
				q.push(make_pair(ny,nx));
			}
		}
	}
}


int main()
{
	cin>>testcase;
	while(testcase--)
	{
		init();
		cin>>chesslen;
		for(int i=0;i<chesslen;++i)
		{
			for(int j=0;j<chesslen;++j)
			{
				maps[i][j]=0;
			}
		}
		int y1,x1;
		int ypos,xpos;
		cin>>y1>>x1;
		cin>>ypos>>xpos;
		maps[y1][x1]=1;
		bfs(y1,x1);
		v.push_back(visited[ypos][xpos]-1);
	}
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
}
