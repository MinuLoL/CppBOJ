#include<bits/stdc++.h>
using namespace std;

int M,N;
int maps[1000][1000];
int visited[1000][1000];
queue<pair<int,int> > q;
//상하좌우 이동
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
//NxM배열안에 존재하는지 확인
bool isInMap(int y, int x){
	return ((y >= 0 && y < N) && (x >= 0 && x < M));
} 
bool com(int a,int b)
{
	if(a>b)
		return true;
	else
		return false;
}
void bfs(int y,int x){
	queue<pair<int,int> > q;

	q.push(make_pair(y,x));
	visited[y][x]=1;
	
	while(!q.empty()){
		y=q.front().first;
		x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInMap(ny,nx)&&!visited[ny][nx]&&maps[ny][nx]==0)
			{
				visited[ny][nx]=visited[y][x]+1;           //중요)최단거리 구하는 식
				q.push(make_pair(ny,nx));
			}
			else if(isInMap(ny,nx)&&com(visited[ny][nx],visited[y][x])&&maps[ny][nx]==0)
			{
				visited[ny][nx]=visited[y][x]+1;           //중요)최단거리 구하는 식
				q.push(make_pair(ny,nx));
			}
			
		}
	}
}

int main()
{
	cin>>M>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cin>>maps[i][j];
		}
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			if(!visited[i][j]&&maps[i][j]==1)
			{
				bfs(i,j);
			}
		}
	}

//	for(int i=0;i<N;++i)
//	{
//		for(int j=0;j<M;++j)
//		{
//			cout<<visited[i][j]<<" ";
//		}
//		cout<<endl;
//	}


	int maxnum=0;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			if(maps[i][j]==0&&visited[i][j]==0)
			{
				cout<<-1;
				return 0;
			}
			if(maxnum<visited[i][j])
			{	
				maxnum=visited[i][j];
			}
		}
	}
	cout<<maxnum-1;
}
