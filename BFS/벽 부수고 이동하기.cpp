#include<bits/stdc++.h>
using namespace std;

int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

char str[1001];
int N,M;
int maps[1001][1001];
bool visited[1001][1001][2]={0,};

bool isInMap(int y,int x)
{
	return ((y>=0&&y<N)&&(x>=0&&x<M));
}

int bfs(int y,int x)
{
	queue<pair<pair<int,int>,pair<int,int> > > q;
	q.push(make_pair(make_pair(y,x),make_pair(0,1)));
	visited[y][x][0]=true;
	while(!q.empty())
	{
		y=q.front().first.first;
		x=q.front().first.second;
		int Breakcnt=q.front().second.first;
		int cnt=q.front().second.second;
		q.pop();
		if(y==N-1&&x==M-1)
		{
			return cnt;
		}
		
		for(int i=0;i<4;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(isInMap(ny,nx))
			{
				if(maps[ny][nx]==1&&Breakcnt==0)
				{
					visited[ny][nx][Breakcnt+1]=true;
					q.push(make_pair(make_pair(ny,nx),make_pair(Breakcnt+1,cnt+1)));
				}
				else if(maps[ny][nx]==0&&visited[ny][nx][Breakcnt]==false)
				{
					visited[ny][nx][Breakcnt]=true;
					q.push(make_pair(make_pair(ny,nx),make_pair(Breakcnt,cnt+1)));
				}
			}
			
		}
	}
	return -1;
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<N;++i)
	{
		cin>>str;
		for(int j=0;j<M;++j)
		{
			maps[i][j]=str[j]-'0';	
		}	
	}

	cout<<bfs(0,0);
	return 0;	
}
