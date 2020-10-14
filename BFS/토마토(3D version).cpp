#include<bits/stdc++.h>
using namespace std;

int M,N,H;
queue<pair<pair<int,int>,int> > q;

int maps[101][101][101];	//3dimension tomato 
int visited[101][101][101];

int dx[]={0,0,-1,1,0,0};	//up,down,left,right,other dimension up,down
int dy[]={1,-1,0,0,0,0};	//same
int dh[]={0,0,0,0,1,-1};	//same

bool isInMap(int y,int x,int h)	//check the position whether is in map
{
	return ((y>=0&&y<N)&&(x>=0&&x<M)&&(h>=0&&h<H));
}

void bfs(void)		
{
	while(!q.empty())
	{
		int h=q.front().second;
		int y=q.front().first.first;
		int x=q.front().first.second;
		q.pop();
		for(int i=0;i<6;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			int nh=h+dh[i];
			if(isInMap(ny,nx,nh)&&!visited[nh][ny][nx]&&maps[nh][ny][nx]==0)
			{
				visited[nh][ny][nx]=visited[h][y][x]+1;
				q.push(make_pair(make_pair(ny,nx),nh));
			}
		}
	}
}

int main()
{
	cin>>M>>N>>H;
	for(int h=0;h<H;++h)
	{
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<M;++j)
			{
				cin>>maps[h][i][j];
				if(maps[h][i][j]==1)
				{
					q.push(make_pair(make_pair(i,j),h));
					visited[h][i][j]=1;
				}
			}
		}
	}
	
	bfs();
	
	for(int h=0;h<H;++h)
	{
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<M;++j)
			{
				cout<<visited[h][i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	int maxnum=0;
	for(int h=0;h<H;++h)
	{
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<M;++j)
			{
				if(maps[h][i][j]==0&&visited[h][i][j]==0)
				{
					cout<<-1;
					return 0;
				}
				if(maxnum<visited[h][i][j])
				{
					maxnum=visited[h][i][j];
				}
			}
		}
	}
	if(maxnum==0)
	{
		cout<<maxnum;
		return 0;
	}
	cout<<maxnum-1;
	return 0;
}
