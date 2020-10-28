#include<bits/stdc++.h>
using namespace std;

int N,M;
int maps[20][20];
int visited[20][20]={0,};
int SharkSize=2;
int sizecnt=0;
int sharkposY;
int sharkposX;

int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

bool isInMap(int y,int x)	//checking in maps
{
	return ((y>=0&&y<N)&&(x>=0&&x<N));
}
bool possiblepass(int y,int x)	//checking Shark can pass  
{
	return	maps[y][x]<=SharkSize;
}

void bfs(int y,int x)
{
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	visited[y][x]=0;
	while(!q.empty())
	{
		y=q.front().first;
		x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInMap(ny,nx)&&possiblepass(ny,nx)&&!visited[ny][nx])
			{
				visited[ny][nx]=visited[y][x]+1;
				q.push(make_pair(ny,nx));
			}
		}	
	}
}

int main()
{
	cin>>N;	//(2<=N<=20)
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cin>>maps[i][j];
			if(maps[i][j]==9)
			{
				sharkposY=i;
				sharkposX=j;
			}
		}
	}
	bfs(sharkposY,sharkposX);//���� ��ġ���� �̵��� �� �ִ� ���
	//�����԰� 1�� ��ġ�� ã�Ƽ� �̵��ؾ���
	 
//	for(int i=0;i<N;++i)
//	{
//		for(int j=0;j<N;++j)
//		{
//			cout<<visited[i][j];
//		}
//		cout<<endl;
//	}
	memset(visited,0,sizeof(visited));
	 
	

}

//2020.10.27	bfs�Ϸ�
//ũ�Ⱑ 2�� �� 1�� ����Ⱑ �ִ� ��ġ�� �̵��ؾ���
 

