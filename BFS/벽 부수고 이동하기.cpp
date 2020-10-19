#include<bits/stdc++.h>
using namespace std;

int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

char str[1001];
int N,M;
int maps[1001][1001];
int visited[1001][1001]={0,};
int cnt=0;
vector<pair<int,int> > v;
int minlen=1000000;

bool isInMap(int y,int x)
{
	return ((y>=0&&y<N)&&(x>=0&&x<M));
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
		for(int i=0;i<4;++i)
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
	cin>>N>>M;
	for(int i=0;i<N;++i)
	{
		cin>>str;
		for(int j=0;j<M;++j)
		{
			maps[i][j]=str[j]-'0';	
		}	
	}
	
	for(int i=0;i<N;++i)	//4방향 중에 이동할 수 있는 0이 하나라도 있는 경우 
	{
		for(int j=0;j<M;++j)
		{
			if(maps[i][j]==1)
			{
				for(int k=0;k<4;++k)
				{
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(isInMap(ny,nx)&&!maps[ny][nx])
					{
						v.push_back(make_pair(i,j));
						break;
					}
				}	
			}	
		}	
	}

	for(int i=0;i<v.size();++i)
	{
		int y=v[i].first;
		int x=v[i].second;
		maps[y][x]=0;
		bfs(0,0);
		if(minlen>visited[N-1][M-1]&&visited[N-1][M-1])
			minlen=visited[N-1][M-1];
		memset(visited,0,sizeof(visited));
		maps[y][x]=1;
	}
	
	if(minlen==1000000)
	{
		cout<<-1;
		return 0;
	}
	cout<<minlen;
	return 0;
	
}
