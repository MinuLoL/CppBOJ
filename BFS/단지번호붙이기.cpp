#include<bits/stdc++.h>
using namespace std;
int N;
int discnt=0;
int cnt=1;
char maps[25][25];
int imap[25][25];
int visited[25][25];

//상하좌우 이동
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<int>v;
 
//NxN배열 안에 있는지 검사
bool isInMap(int y,int x)
{
	return ((y >= 0 && y < N) && (x >= 0 && x < N));
}
 void init()
 {
 	cnt=1;
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
		for(int i=0;i<4;++i)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isInMap(ny,nx)&&!visited[ny][nx]&&imap[ny][nx])
			{
				visited[ny][nx]=1;
				cnt++;
				q.push(make_pair(ny,nx));
			}
		}
	}
}
 
int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cin>>maps[i][j];
		}
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			imap[i][j]=maps[i][j]-'0';
		}
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			if(!visited[i][j]&&imap[i][j])
			{
				bfs(i,j);
				discnt++;
				v.push_back(cnt);
				init();
			}
		}
	}
	sort(v.begin(),v.end());
	cout<<discnt<<endl;
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<endl;
	}
}
