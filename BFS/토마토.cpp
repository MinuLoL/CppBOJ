#include<bits/stdc++.h>
using namespace std;

int M,N;
queue<pair<int,int> > q;

int maps[1001][1001];
int visited[1001][1001];

//상하좌우 이동
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
//NxM배열안에 존재하는지 확인
bool isInMap(int y, int x){
	return ((y >= 0 && y < N) && (x >= 0 && x < M));
} 
void bfs(void){
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
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
			if(maps[i][j]==1)
			{
				q.push(make_pair(i,j)); //(STAR!!) 1인위치에서 BFS탐색을 하기위해 q에 넣어줌
				visited[i][j]=1;
			}
		}
	}
	bfs();
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
	if(maxnum==0)
	{
		cout<<maxnum;
		return 0;
	}
	cout<<maxnum-1;
}
