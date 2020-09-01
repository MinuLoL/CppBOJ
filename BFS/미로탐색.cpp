#include<bits/stdc++.h>
using namespace std;
int N,M;
char maps[100][100];
int imap[100][100];
int visited[100][100];

//상하좌우 이동
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

//NxM배열안에 존재하는지 확인
bool isInMap(int y, int x){
	return ((y >= 0 && y < N) && (x >= 0 && x < M));
} 

//너비우선탐색(큐를 이용한)
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
			if(isInMap(ny,nx)&&!visited[ny][nx]&&imap[ny][nx])
			{
				visited[ny][nx]=visited[y][x]+1;           //중요)최단거리 구하는 식
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
		for(int j=0;j<M;++j)
		{
			cin>>maps[i][j];
		}
	}
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			imap[i][j]=maps[i][j]-'0';
		}
	}
	bfs(0,0);
	cout<<visited[N-1][M-1];
}
